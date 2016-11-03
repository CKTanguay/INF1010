/**
*\ file : PouvoirHallucinogene.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef POUVOIR_HALLUCINOGENE_H
#define POUVOIR_HALLUCINOGENE_H

#include "Pouvoir.h"
#include "EtatConfus.h"

using namespace std;

class PouvoirHallucinogene :public Pouvoir 
{
public:
	PouvoirHallucinogene();
	PouvoirHallucinogene(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirHallucinogene();

	void appliquerEffetOffensif(Creature& creatureEnnemie);

	friend ostream& operator<<(ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene);

private:
	int duree_;
};
#endif