/**
*\ file : GreenBull.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "ObjetMagique.h"
#ifndef GREEN_BULL_H
#define GREEN_BULL_H
using namespace std;
class GreenBull :public ObjetMagique {
	
public:
	GreenBull();
	GreenBull(const string &nom, int bonus);
	friend ostream& operator<<(ostream& os, const GreenBull& greenBull);
	void utiliserSur(Creature& creature) const;
};
#endif

