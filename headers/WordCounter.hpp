/*
*WordCounter.hpp
*
*
*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class WordCounter
{
	public:
		
		WordCounter(const string); //Constructeur
		string getligne();
		void setligne(string ligne);

		//Fonctions membres
		unsigned int count();
		bool isURL(string);
		bool isException(string);
		int ajouter(string);

	private:
		string ligne;
};
