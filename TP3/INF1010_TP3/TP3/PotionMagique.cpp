/**
*\ file : PotionMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "PotionMagique.h"

PotionMagique::PotionMagique() {}

PotionMagique::PotionMagique(const string &nom, int bonus):ObjetMagique(nom,bonus){}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser l'objet PotionMagique sur une créature.
* \param [IN/OUT] creature Ce paramètre représente la créature sur laquelle on utlise l'objet PotionMagique.
*/

void PotionMagique::utiliserSur(Creature& creature) const 
{
	if ((creature.getPointDeVieTotal() - creature.getPointDeVie()) >= getBonus()) 
	{
		creature.setPointDeVie(creature.getPointDeVie() + getBonus());
	}

	else 
	{
		creature.setPointDeVie(creature.getPointDeVieTotal());
	}
}


/**
* L'opérateur surchargé affiche les informations de l'objet PotionMagique passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] potionMagique Ce paramètre représente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const PotionMagique& potionMagique)
{
	os << "L'objet Potion soigne de " << potionMagique.getBonus() << " points de vie." << endl;

	return os;
}
