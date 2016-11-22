#ifndef  FONCTEUR
#define  FONCTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la cr�ature pass�e en argument
class FoncteurObtenirAttaqueCreature
{
public:
	FoncteurObtenirAttaqueCreature() {}
	~FoncteurObtenirAttaqueCreature() {}

	unsigned int operator() (const Creature* creature) const {
		return creature->obtenirAttaque();
	}
};

// Ce foncteur prend en argument deux pointeurs de cr�ature et renvoie true 
// si la premi�re cr�ature a une attaque inf�rieure � celle de la deuxi�me.
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

// Ce foncteur prend en argument deux pointeurs de dresseurs et renvoie true
// si le premier a un nom strictement inf�rieur au nom du second. (alphanum�rique)
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

// Ce foncteur prend en argument deux pointeurs de pouvoir et renvoie true 
// si le premier pouvoir a un nombre de d�g�ts inf�rieur � celui du deuxi�me.
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

// Ce foncteur prend en argument un pointeur de cr�ature et renvoie true 
// si cette cr�ature a le m�me nom que l�attribut de la classe correspondant.

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

// Ce foncteur prend en argument un pointeur de cr�ature et renvoie true 
// si cette cr�atures est �gale � l�attribut creature du foncteur.
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

// Ce foncteur prend en argument un pointeur vers une cr�ature et incr�mente une variable interne 
// si les points de vie de la cr�ature sont entre ces bornes.
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

// Ce foncteur permet de g�n�rer un nombre al�atoire compris dans un intervalle.
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