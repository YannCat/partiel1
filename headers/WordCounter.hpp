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

		//Fonctions membres
		unsigned int count();

	private:
		string ligne;
};
