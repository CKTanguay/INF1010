/**
*\ file : Elixir.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

using namespace std;

class Elixir :public PotionMagique 
{
public:
	Elixir();
	Elixir(const string &nom, int bonus);
	friend ostream& operator<<(ostream& os, const Elixir& elixir);
	void utiliserSur(Creature& creature) const;
};
#endif

