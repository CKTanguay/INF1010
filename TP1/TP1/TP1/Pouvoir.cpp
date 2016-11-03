/**
*\ file : Pouvoir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include "Pouvoir.h"
#include <clocale>  // pour setlocale

Pouvoir::Pouvoir()
{
	nom_ = "";
	degat_ = 0;
	energieNeccessaire_ = 0;

}

Pouvoir::Pouvoir(string nom, int degat, int energieNessessaire)
{
	nom_ = nom;
	degat_ = degat;
	energieNeccessaire_ = energieNessessaire;
}

Pouvoir::~Pouvoir() {}

void Pouvoir::setNom(string nom)
{
	nom_ = nom;
}

void Pouvoir::setDegat(int degat)
{
	degat_ = degat;
}

void Pouvoir::setEnergieNeccessaire(int energieNeccessaire)
{
	energieNeccessaire_ = energieNeccessaire;
}

string Pouvoir::getNom() const
{
	return nom_;
}

int Pouvoir::getDegat() const
{
	return degat_;
}

int Pouvoir::getEnergieNeccessaire() const
{
	return energieNeccessaire_;
}


/**
* La fonction permet tout simplement l'affichage des informations sur la créature.
*/

void Pouvoir::affichage()
{
	setlocale(LC_ALL, "");

	cout << "Son pouvoir est : " << nom_ << " necessite " << energieNeccessaire_ << " mana et inflige " << degat_ << " degats" << endl;
}