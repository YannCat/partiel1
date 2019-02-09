/*
*
*WordCounter.cpp
*
*/

#include "WordCounter.hpp"

WordCounter::WordCounter(const string sentence)
{
	this->ligne = sentence;
}

string WordCounter::getligne()
{
	return this->ligne;
}

void WordCounter::setligne(string ligne)
{
	this->ligne = ligne;
}

unsigned int WordCounter::count()
{
	int compt = 0;
	string mot;
	istringstream courant(this->ligne);

	while(courant >> mot)
	{
		if(!isException(mot))
		{	
			compt++;
		}
		else
		{
			compt = compt + ajouter(mot);
		}
	}
	return compt;
}

bool WordCounter::isURL(string mot)		//test URL
{
	if((mot.find("http://") != string::npos) || (mot.find("https://") != string::npos) || (mot.find("www.") != string::npos))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool WordCounter::isException(string mot)	// Test des accents (pas pris en compte par isalpha)
{
	if((mot.compare("é") == 0) || (mot.compare("éè") == 0) || (mot.compare("É") == 0) || (mot.compare("Öé") == 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}


int WordCounter::ajouter(string mot)	//pour diminuer la taille de la fonction count
{
	bool prec = false;
	int nb_mots = 0;

	if(isURL(mot))
	{
		nb_mots = 0;
	}
	else
	{
		for(int i = 0; i < int(mot.size()); i++)
		{
			if((prec == false) && (isalpha(mot[i]) != 0))
			{
				prec = true;
				nb_mots++;
			}
			if((mot[i] >= 0 && mot[i] <= 64) || (mot[i] >= 91 && mot[i] <= 96) || (mot[i] >= 123 && mot[i] <= 127)) //Détection de fin de chaîne hors accent
			{
				prec = false;
			}
		}
	}
	return nb_mots;
}
