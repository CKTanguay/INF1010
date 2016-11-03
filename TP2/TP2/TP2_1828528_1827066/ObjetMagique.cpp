/**
*\ file : ObjetMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 03/10/16
*\ Cr�� le : 28/09/16
*/

#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique(){}

ObjetMagique::ObjetMagique(const string & nom, int bonus): nom_(nom), bonus_(bonus){}

ObjetMagique::~ObjetMagique(){}

#pragma region GET/SET

string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

#pragma endregion


/**
* L'op�rateur surcharg� affiche les informations de l'objet magique pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] objetMagique Ce param�tre repr�sente l'objet magique dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const ObjetMagique& objetMagique)
{
	os << "L'objet " << objetMagique.obtenirNom() << " fournit un bonus de " << objetMagique.obtenirBonus() << "." << endl;
	return os;
}