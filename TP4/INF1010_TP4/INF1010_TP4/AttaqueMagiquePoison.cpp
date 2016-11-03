/**
*\ file : AttaqueMagiquePoison.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 01/11/16
*\ Cr�� le : 29/10/16
*/

#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison():AttaqueMagique(2) {}
AttaqueMagiquePoison::AttaqueMagiquePoison(int duree):AttaqueMagique(duree) {}
AttaqueMagiquePoison::~AttaqueMagiquePoison() {}


/**
* La fonction estFini retourne true ou false selon la dur�e.
* \return La fonction retourne true si la dur�e est de 0, false sinon.
*/

bool AttaqueMagiquePoison::estFini() const 
{
	return (duree_ == 0);
}


/**
* La fonction appliquerAttaque applique l'effet d'une attaque sur une cr�ature pass�e en param�tre.
* \param [OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on applique l'attaque magique poison.
*/

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature) 
{
	srand(time(NULL));
	if (!estFini()) {
		if (rand() % 3) {}
		else if (creature.obtenirEnergie() >= 5) {
			creature.modifierEnergie(creature.obtenirEnergie() - 2);
				cout << creature.obtenirNom() << " a perdu 2 points d'�nergie d� � l'attaque poison" << std::endl;
		}
		duree_--;
	}
}


/**
* La fonction obtenirTypeAttaque permet de retourner le type de l'attaque.
* \return La valeur de retour de la fonction est une cha�ne de caract�res repr�sentant le type de l'attaque, soit AttaqueMagiquePoison.
*/

string AttaqueMagiquePoison::obtenirTypeAttaque() const 
{
		return typeid(*this).name();
}