/**
*\ file : OutilScientifique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "OutilScientifique.h"

OutilScientifique::OutilScientifique(const string & nom, const string & description) :
	nom_(nom), description_(description)
{
}

OutilScientifique::~OutilScientifique()
{
}

string OutilScientifique::getNom() const
{
	return nom_;
}

string OutilScientifique::getDescription() const
{
	return description_;
}

void OutilScientifique::setNom(const string& nom)///////
{
	nom_ = nom;
}

void OutilScientifique::setDescription(const string& description)////////
{
	description_ = description;
}

void OutilScientifique::utiliser(Creature & creature)
{
	//methode de classe de base
	//ne fait rien
}

ostream & operator<<(ostream & os, const OutilScientifique & outil)
{
	return os << "l'outil " << outil.nom_ << " Permet de " << outil.description_;
}
