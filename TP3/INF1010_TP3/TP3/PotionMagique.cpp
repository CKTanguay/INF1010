/**
*\ file : PotionMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "PotionMagique.h"

PotionMagique::PotionMagique() {}

PotionMagique::PotionMagique(const string &nom, int bonus):ObjetMagique(nom,bonus){}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser l'objet PotionMagique sur une cr�ature.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on utlise l'objet PotionMagique.
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
* L'op�rateur surcharg� affiche les informations de l'objet PotionMagique pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] potionMagique Ce param�tre repr�sente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const PotionMagique& potionMagique)
{
	os << "L'objet Potion soigne de " << potionMagique.getBonus() << " points de vie." << endl;

	return os;
}
