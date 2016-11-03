/**
*\ file : EtatEndormi.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "EtatEndormi.h"

EtatEndormi::EtatEndormi()
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const string& nom) : EtatCreature(nom)
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::~EtatEndormi() {}


/**
* La fonction peutAttaquer pour cet état retourne que la créature ne peut pas attaquer.
* \return La valeur de retour par défaut est false.
*/

bool EtatEndormi::peutAttaquer() const
{
	return false;
}


/**
* La fonction appliquerEtat applique l'état déterminé à la créature passée en paramètre.
* \param [IN/OUT] creature Ce paramètre représente la créature dont l'état actuel est modifié.
*/

void EtatEndormi::appliquerEtat(Creature& creature)
{
	if (duree_ > 0)
		duree_--;
}


/**
* La fonction estFini vérifie si la durée est finie.
* \return La fonction retourne true si la duree est plus petite ou égale à 0, false sinon.
*/

bool EtatEndormi::estFini() const
{
	if (duree_ <= 0)
		return true;

	return false;
}


/**
* L'opérateur surchargé affiche les informations de l'état passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] etatEndormi Ce paramètre représente l'état dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const EtatEndormi& etatEndormi)
{
	os << "état endormi : " << etatEndormi.getNom() << " durera " << etatEndormi.duree_ << endl;

	return os;
}
