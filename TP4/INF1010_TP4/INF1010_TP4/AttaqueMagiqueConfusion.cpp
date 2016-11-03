/**
*\ file : AttaqueMagiqueConfusion.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 01/11/16
*\ Cr�� le : 29/10/16
*/

#include "AttaqueMagiqueConfusion.h"

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(2) {}
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree) : AttaqueMagique(duree) {}
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion() {}


/**
* La fonction estFini retourne true ou false selon la dur�e.
* \return La fonction retourne true si la dur�e est de 0, false sinon.
*/

bool AttaqueMagiqueConfusion::estFini() const 
{
	return (duree_ == 0);
}


/**
* La fonction appliquerAttaque applique l'effet d'une attaque sur une cr�ature pass�e en param�tre.
* \param [OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on applique l'attaque magique de confusion.
*/

void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature) 
{
	srand(time(NULL));
	if (!estFini()) {
		if (rand() % 3) {}
		else if (creature.obtenirPointDeVie() >= 5) {
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
			cout << creature.obtenirNom() << " a perdu 2 points d'�nergie d� � l'attaque poison" << std::endl;
		}
		duree_--;
	}
}


/**
* La fonction obtenirTypeAttaque permet de retourner le type de l'attaque.
* \return La valeur de retour de la fonction est une cha�ne de caract�res repr�sentant le type de l'attaque, soit AttaqueMagiqueConfusion.
*/

string AttaqueMagiqueConfusion::obtenirTypeAttaque() const 
{
	return typeid(*this).name();
}