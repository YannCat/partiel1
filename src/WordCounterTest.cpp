/*
*
*WordCounterTest.cpp
*
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WordCounter.hpp"


TEST_CASE("Tests Basic", "[WordCounter]")
{
	WordCounter test1("C'est le premier test !"); //un mot est une succession de caractères alphabétiques séparés d'un autre mot par un ou plusieurs espaces, ou d’un caractère de ponctuation
	CHECK(test1.count() == 5);
}

TEST_CASE("Tests chiffre", "[WordCounter]") // une succession de chiffres n’est pas un mot
{
	WordCounter test2("Un chèque de 35000€ vous interesse-t-il ?");
	CHECK(test2.count() == 7);
}

TEST_CASE("Tests symbole", "[WordCounter]") //une succession de symbole non-alphabétique n’est pas un mot
{
	WordCounter test3("Quand je suis énervé, je dis #@!&?% !");
	CHECK(test3.count() == 6);
}

TEST_CASE("Test URL", "[WordCounter]") //une URL (adresse internet) n’est pas un mot
{
	WordCounter test4("Faites un tour sur le site de mon entreprise : http://www.e55c.com/");
	CHECK(test4.count() == 9);
}
