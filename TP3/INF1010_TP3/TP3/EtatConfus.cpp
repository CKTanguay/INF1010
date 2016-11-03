/**
*\ file : EtatConfus.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "EtatConfus.h"

EtatConfus::EtatConfus()
{
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const string& nom) :EtatCreature(nom)
{
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat_confus;
}

EtatConfus::~EtatConfus() {}


/**
* La fonction peutAttaquer pour cet état retourne que la créature peut attaquer avec une certaine probabilité.
* \return La valeur de retour est true si la valeur aléatoire est divisible par deux, false sinon.
*/

bool EtatConfus::peutAttaquer() const
{
	return rand() % 2 == 0;
}


/**
* La fonction appliquerEtat applique l'état déterminé à la créature passée en paramètre.
* \param [IN/OUT] creature Ce paramètre représente la créature dont l'état actuel est modifié.
*/

void EtatConfus::appliquerEtat(Creature& creature)
{
	if (rand() % 3 == 0)
	{
		if (creature.getPointDeVie() * 0.95 >= 5)
		{
			creature.setPointDeVie(creature.getPointDeVie() * 0.95);
		}

		else
		{	
			if (creature.getPointDeVie() >= 5)
				creature.setPointDeVie(creature.getPointDeVie() - 5);
			else
				creature.setPointDeVie(0);
		}
	}

	duree_--;
}


/**
* La fonction estFini vérifie si la durée est finie, selon des probabilités.
* \return La fonction retourne true si la valeur aléatoire est divisible par trois, false sinon.
*/

bool EtatConfus::estFini() const
{
	if (rand() % 3 == 0)
	{
		return true;
	}

	else
		return (duree_ <= 0);
}


/**
* L'opérateur surchargé affiche les informations de l'état passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] etatConfus Ce paramètre représente l'état dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const EtatConfus& etatConfus)
{
	os << "état confus : " << etatConfus.getNom() << "durera " << etatConfus.duree_ << endl;

	return os;
}