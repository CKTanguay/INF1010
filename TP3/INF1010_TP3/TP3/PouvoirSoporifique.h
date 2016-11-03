/**
*\ file : PouvoirSoporifique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "Pouvoir.h"
#include "EtatEndormi.h"

#ifndef POUVOIR_SOPORIFIQUE_H
#define POUVOIR_SOPORIFIQUE_H

using namespace std;

class PouvoirSoporifique :public Pouvoir 
{
public:
	PouvoirSoporifique();
	PouvoirSoporifique(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirSoporifique();
	void appliquerEffetOffensif(Creature& creatureEnnemie);

	friend ostream& operator<<(ostream& os, const PouvoirSoporifique& pouvoirSoporifique);

private:
	int duree_;
};
#endif