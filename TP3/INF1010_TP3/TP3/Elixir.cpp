/**
*\ file : Elixir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "Elixir.h"

Elixir::Elixir(){}
Elixir::Elixir(const string &nom, int bonus) :PotionMagique(nom, bonus) {}


/**
* La fonction utiliserSur ci-dessous surcharge celle de la classe de base pour utiliser des items magiques sur une cr�ature.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on utlise l'objet magique et la potion magique
*/

void Elixir::utiliserSur(Creature& creature) const 
{
	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);
}


/**
* L'op�rateur surcharg� affiche les informations de l'�lixir pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] elixir Ce param�tre repr�sente l'�lixir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const Elixir& elixir)
{
	os << "L'objet Elixir donne " << elixir.getBonus() << " points d'�nergie." << endl;

	return os;
}
