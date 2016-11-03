/**
*\ file : AttaqueMagiquePoison.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#ifndef ATTAQUE_MAGIQUE_POISON_H
#define ATTAQUE_MAGIQUE_POISON_H

#include "AttaqueMagique.h"
class AttaqueMagiquePoison : public AttaqueMagique {
public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(int duree);
	~AttaqueMagiquePoison();
	virtual string obtenirTypeAttaque()const;
	bool estFini() const;
	void appliquerAttaque(Creature& creature);
};


#endif