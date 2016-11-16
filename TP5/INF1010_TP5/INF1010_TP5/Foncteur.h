#ifndef  FONCTEUR
#define  FONCTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
	FoncteurObtenirAttaqueCreature() {}
	~FoncteurObtenirAttaqueCreature() {}

	unsigned int operator() (const Creature* creature) const {
		return creature->obtenirAttaque();
	}
};


class FoncteurComparerCreatures
{
public:
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator()(const Creature* creature1, const Creature* creature2) const
	{
		return(creature1->obtenirAttaque() < creature2->obtenirAttaque());
	}
};


class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}

	bool operator()(const Dresseur* dresseur1, const Dresseur* dresseur2) const
	{
		return(dresseur1->obtenirNom() < dresseur2->obtenirNom());		
	}
};


class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2)
	{
		return(pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat());
	}
};


class FoncteurCreatureDeMemeNom
{
public:
	FoncteurCreatureDeMemeNom() {}
	~FoncteurCreatureDeMemeNom() {}
	FoncteurCreatureDeMemeNom(const std::string& nom) :nom_(nom) {}



private:
	std::string nom_;
};

#endif;