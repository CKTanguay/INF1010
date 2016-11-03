/**
*\ file : GreenBull.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "GreenBull.h"

GreenBull::GreenBull() {}
GreenBull::GreenBull(const string &nom, int bonus) :ObjetMagique(nom, bonus) {}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser l'objet GreenBull sur une créature.
* \param [IN/OUT] creature Ce paramètre représente la créature sur laquelle on utlise l'objet GreenBull.
*/

void GreenBull::utiliserSur(Creature& creature) const 
{
	if ((creature.getEnergieTotale() - creature.getEnergie()) > getBonus()) 
	{
		creature.setEnergie(creature.getEnergie() + getBonus());
	}

	else 
	{
		creature.setEnergie(creature.getEnergieTotale());
	}
}


/**
* L'opérateur surchargé affiche les informations de l'objet GreenBull passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] greenBul Ce paramètre représente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const GreenBull& greenBull)
{
	os << "L'objet greenBull fournit " << greenBull.getBonus() << " point(s) d'énergie." << endl;

	return os;
}
