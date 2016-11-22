/**
*\ file : AttaqueMagiquePoison.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
*/
#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFIÉ
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFIÉ
{}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}
/**
* La fonction appliquerAttaque applique l'effet d'une attaque sur une créature passée en paramètre.
* \param [OUT] creature Ce paramètre représente la créature sur laquelle on applique l'attaque magique de confusion.
*/
void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.obtenirEnergie() >= 5)
	{
		unsigned int energie = creature.obtenirEnergie();
		if (genNbAlea_() == 0)
		{
			creature.modifierEnergie(energie - 2);
		}
		duree_--;
	}
}
/**
* La fonction estFini retourne true ou false selon la durée.
* \return La fonction retourne true si la durée est de 0, false sinon.
*/
bool AttaqueMagiquePoison::estFini() const
{
	return (duree_ <= 0);
}
/**
* La fonction obtenirTypeAttaque permet de retourner le type de l'attaque.
* \return La valeur de retour de la fonction est une chaîne de caractères représentant le type de l'attaque, soit AttaqueMagiqueConfusion.
*/
std::string AttaqueMagiquePoison::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
