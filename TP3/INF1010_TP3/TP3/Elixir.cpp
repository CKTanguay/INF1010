/**
*\ file : Elixir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "Elixir.h"

Elixir::Elixir(){}
Elixir::Elixir(const string &nom, int bonus) :PotionMagique(nom, bonus) {}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser des items magiques sur une créature.
* \param [IN/OUT] creature Ce paramètre représente la créature sur laquelle on utlise l'objet magique et la potion magique
*/

void Elixir::utiliserSur(Creature& creature) const 
{
	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);
}


/**
* L'opérateur surchargé affiche les informations de l'élixir passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] elixir Ce paramètre représente l'élixir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const Elixir& elixir)
{
	os << "L'objet Elixir donne " << elixir.getBonus() << " points d'énergie." << endl;

	return os;
}
