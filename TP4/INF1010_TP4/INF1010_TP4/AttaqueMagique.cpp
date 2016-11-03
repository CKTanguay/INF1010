/**
*\ file : AttaqueMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#include "AttaqueMagique.h"

using namespace std;

AttaqueMagique::AttaqueMagique() 
{
	duree_ = 0;
}

AttaqueMagique::AttaqueMagique(int duree) 
{
	duree_ = duree;
}

AttaqueMagique::~AttaqueMagique() {}

int AttaqueMagique::obtenirDuree() const 
{
	return duree_;
}

void AttaqueMagique::modifierDuree(int duree) 
{
	duree_ = duree;
}


/**
* La fonction obtenirTypeAttaque permet de retourner le type de l'attaque.
* \return La valeur de retour de la fonction est une chaîne de caractères représentant le type de l'attaque.
*/

string AttaqueMagique::obtenirTypeAttaque() const 
{
	return typeid(*this).name();
}


/**
* La fonction estFini retourne toujours que la durée est finie.
* \return La fonction retourne true.
*/

bool AttaqueMagique::estFini() const 
{
	return true;
}


/**
* La fonction appliquerAttaque ne fait rien du tout ici.
* \param [IN/OUT] creature Ce paramètre représente la créature avec laquelle on ne fait rien.
*/

void AttaqueMagique::appliquerAttaque(Creature& creature) {}


/**
* L'opérateur surchargé affiche les informations de l'attaque passée en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] attaqueMagique Ce paramètre représente l'attaque dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const AttaqueMagique& attaqueMagique)
{
	return os << attaqueMagique.obtenirTypeAttaque() << " qui a une durée de " << attaqueMagique.obtenirDuree() << endl;
}
