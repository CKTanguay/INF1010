/**
*\ file : AttaqueMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#ifndef ATTAQUE_MAGIQUE_H
#define ATTAQUE_MAGIQUE_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>
#include <typeinfo>
#include <string>
#include "Creature.h"

using namespace std;

class AttaqueMagique {
public:
	AttaqueMagique();
	AttaqueMagique(int duree);
	~AttaqueMagique();
	int obtenirDuree() const;
	void modifierDuree(int duree);
	virtual string obtenirTypeAttaque()const;
	bool estFini()const;
	virtual void appliquerAttaque(Creature& creature) = 0;

	friend ostream& operator<<(ostream& os, const AttaqueMagique& attaqueMagique);

protected:
	int duree_;
private:
};
#endif