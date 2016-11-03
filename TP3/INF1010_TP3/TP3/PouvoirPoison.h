/**
*\ file : PouvoirPoison.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef POUVOIR_POISON_H
#define  POUVOIR_POISON_H

#include "Pouvoir.h"
#include "EtatEmpoisonne.h"

using namespace std;

class PouvoirPoison :public Pouvoir 
{
public:
	PouvoirPoison();
	PouvoirPoison(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirPoison();
	void appliquerEffetOffensif(Creature& creatureEnnemie);

	friend ostream& operator<<(ostream& os, const PouvoirPoison& pouvoirPoison);

private:
	int duree_;
};
#endif