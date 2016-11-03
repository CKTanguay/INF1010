/**
*\ file : AttaqueMagiqueConfusion.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 01/11/16
*\ Cr�� le : 29/10/16
*/

#ifndef ATTAQUE_MAGIQUE_CONFUSION_H
#define ATTAQUE_MAGIQUE_CONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique {
public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(int duree);
	~AttaqueMagiqueConfusion();
	bool estFini() const;
	void appliquerAttaque(Creature& creature);
	virtual string obtenirTypeAttaque()const;
};

#endif
