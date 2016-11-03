/**
*\ file : Pouvoir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
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
* La fonction construit un pouvoir identique à celui passé en paramètre
* \param [IN] pouvoir Ce paramètre représente le pouvoir à copier.
* \return La fonction retourne le pouvoir qui a été construit.
*/

Pouvoir::Pouvoir(const Pouvoir& pouvoir) {
	nom_=pouvoir.nom_;
	nombreDeDegat_=pouvoir.nombreDeDegat_;
	energieNecessaire_=pouvoir.energieNecessaire_;
}

/**
* L'opérateur surchargé remplace les valeurs des attributs du pouvoir courant par celles du pouvoir en paramètre.
* \param [IN] pouvoir Ce paramètre représente le pouvoir duquel on copie les valeurs.
*/

void Pouvoir::operator=(const Pouvoir& pouvoir) {
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
}


/**
* L'opérateur surchargé vérifie que le nom du povoir courant est identique au nom du pouvoir en paramètre.
* \param [IN] pouvoir Ce paramètre représente le pouvoir avec lequel on veut comparer les noms.
* \return La valeur de retour de la fonction est true si les noms sont identiques et false sinon.
*/

bool Pouvoir::operator==(const Pouvoir& pouvoir) 
{
	return (nom_ == pouvoir.obtenirNom());
}


/**
* L'opérateur surchargé affiche les informations du pouvoir passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] pouvoir Ce paramètre représente le pouvoir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const Pouvoir& pouvoir)
{
	os << pouvoir.nom_ << " possède un nombre de dégats de " << pouvoir.nombreDeDegat_ << " et une énergie nécessaire de " << pouvoir.energieNecessaire_  <<"."<< endl;

	return os;
}
