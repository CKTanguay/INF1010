/**
*\ file : ObjetMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include "ObjetMagique.h"
#include <clocale>  // pour setlocale

ObjetMagique::ObjetMagique()
{
	nom_ = "";
	bonus_ = 0;
}

ObjetMagique::ObjetMagique(string nom, int bonus)
{
	nom_ = nom;
	bonus_ = bonus;
}

ObjetMagique::~ObjetMagique() {}

void ObjetMagique::setNom(string nom)
{
	nom_ = nom;
}

void ObjetMagique::setBonus(int bonus)
{
	bonus_ = bonus;
}

string ObjetMagique::getNom()const
{
	return nom_;
}

int ObjetMagique::getBonus()const
{
	return bonus_;
}


/**
* La fonction permet tout simplement l'affichage du bonus de l'objet magique.
*/

void ObjetMagique::affichage()
{
	setlocale(LC_ALL, "");

	cout << "L'objet " << nom_ << " fournit un bonus de " << bonus_ << endl;
}