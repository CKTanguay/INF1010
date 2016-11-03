/**
*\ file : AttaqueMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 01/11/16
*\ Cr�� le : 29/10/16
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
* \return La valeur de retour de la fonction est une cha�ne de caract�res repr�sentant le type de l'attaque.
*/

string AttaqueMagique::obtenirTypeAttaque() const 
{
	return typeid(*this).name();
}


/**
* La fonction estFini retourne toujours que la dur�e est finie.
* \return La fonction retourne true.
*/

bool AttaqueMagique::estFini() const 
{
	return true;
}


/**
* La fonction appliquerAttaque ne fait rien du tout ici.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature avec laquelle on ne fait rien.
*/

void AttaqueMagique::appliquerAttaque(Creature& creature) {}


/**
* L'op�rateur surcharg� affiche les informations de l'attaque pass�e en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] attaqueMagique Ce param�tre repr�sente l'attaque dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const AttaqueMagique& attaqueMagique)
{
	return os << attaqueMagique.obtenirTypeAttaque() << " qui a une dur�e de " << attaqueMagique.obtenirDuree() << endl;
}
