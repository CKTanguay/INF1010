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
		return (dresseur1->obtenirNom() < dresseur2->obtenirNom());		
	}
};


class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2)
	{
		return (pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat());
	}
};


class FoncteurCreatureDeMemeNom
{
public:
	FoncteurCreatureDeMemeNom() {}
	~FoncteurCreatureDeMemeNom() {}
	FoncteurCreatureDeMemeNom(const std::string& nom) :nom_(nom) {}

	bool operator()(const Creature* creature) const
	{
		return(nom_ == creature->obtenirNom());
	}


private:
	std::string nom_;
};


class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures() {}
	~FoncteurEgalCreatures() {}
	FoncteurEgalCreatures(Creature* creature) :creature_(creature) {}

	bool operator()(const Creature* creature) const
	{
		return(creature_ == creature);
	}

private:
	Creature* creature_;
};


class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie() {}
	~FoncteurCreatureVie() {}
	FoncteurCreatureVie(unsigned int vieMinimale, unsigned int vieMaximale) :vieMinimale_(vieMinimale), vieMaximale_(vieMaximale), compteur_(0) {}

	void operator()(const Creature* creature)
	{
		if (creature->obtenirPointDeVie() > vieMinimale_ && creature->obtenirPointDeVie() < vieMaximale_)
			compteur_++;
	}

	unsigned int getCompteur() const
	{
		return compteur_;
	}

private:
	unsigned int vieMinimale_;
	unsigned int vieMaximale_;
	unsigned int compteur_;
};


class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() :borneInferieure_(RAND_MIN_DEFAUT), borneSuperrieure_(RAND_MAX_DEFAUT) {}
	~FoncteurGenerateurNombresAlea() {}
	FoncteurGenerateurNombresAlea(unsigned int borneMinimale, unsigned int borneMaximale) :borneInferieure_(borneMinimale), 
		borneSuperrieure_(borneMaximale) {}

	unsigned int operator()()
	{
		return(rand() % (borneSuperrieure_ - borneInferieure_ + 1) + borneInferieure_);
	}

private:
	unsigned int borneInferieure_;
	unsigned int borneSuperrieure_;
};

#endif;