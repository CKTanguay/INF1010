/**
*\ file : Pouvoir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 03/10/16
*\ Cr�� le : 28/09/16
*/

#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir(){}

Pouvoir::Pouvoir(const  string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire){}

Pouvoir::~Pouvoir(){}

#pragma region GET/SET

 string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

#pragma endregion


/**
* La fonction construit un pouvoir identique � celui pass� en param�tre
* \param [IN] pouvoir Ce param�tre repr�sente le pouvoir � copier.
* \return La fonction retourne le pouvoir qui a �t� construit.
*/

Pouvoir::Pouvoir(const Pouvoir& pouvoir) {
	nom_=pouvoir.nom_;
	nombreDeDegat_=pouvoir.nombreDeDegat_;
	energieNecessaire_=pouvoir.energieNecessaire_;
}

/**
* L'op�rateur surcharg� remplace les valeurs des attributs du pouvoir courant par celles du pouvoir en param�tre.
* \param [IN] pouvoir Ce param�tre repr�sente le pouvoir duquel on copie les valeurs.
*/

void Pouvoir::operator=(const Pouvoir& pouvoir) {
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
}


/**
* L'op�rateur surcharg� v�rifie que le nom du povoir courant est identique au nom du pouvoir en param�tre.
* \param [IN] pouvoir Ce param�tre repr�sente le pouvoir avec lequel on veut comparer les noms.
* \return La valeur de retour de la fonction est true si les noms sont identiques et false sinon.
*/

bool Pouvoir::operator==(const Pouvoir& pouvoir) 
{
	return (nom_ == pouvoir.obtenirNom());
}


/**
* L'op�rateur surcharg� affiche les informations du pouvoir pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] pouvoir Ce param�tre repr�sente le pouvoir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const Pouvoir& pouvoir)
{
	os << pouvoir.nom_ << " poss�de un nombre de d�gats de " << pouvoir.nombreDeDegat_ << " et une �nergie n�cessaire de " << pouvoir.energieNecessaire_  <<"."<< endl;

	return os;
}
