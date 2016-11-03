/**
*\ file : PotionMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef POTION_MAGIQUE_H
#define POTION_MAGIQUE_H

#include "ObjetMagique.h"

using namespace std;

class PotionMagique :public ObjetMagique 
{
public:
	PotionMagique();
	PotionMagique(const string &nom, int bonus);

	friend ostream& operator<<(ostream& os, const PotionMagique& potionMagique);

	void utiliserSur(Creature& creature) const;
};
#endif
