/**
*\ file : GreenBull.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "GreenBull.h"

GreenBull::GreenBull() {}
GreenBull::GreenBull(const string &nom, int bonus) :ObjetMagique(nom, bonus) {}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser l'objet GreenBull sur une cr�ature.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on utlise l'objet GreenBull.
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
* L'op�rateur surcharg� affiche les informations de l'objet GreenBull pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] greenBul Ce param�tre repr�sente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const GreenBull& greenBull)
{
	os << "L'objet greenBull fournit " << greenBull.getBonus() << " point(s) d'�nergie." << endl;

	return os;
}
