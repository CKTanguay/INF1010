/**
*\ file : EtatCreature.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "EtatCreature.h"

EtatCreature::EtatCreature()
{
	type_ = TypeEtat_normal;
}

EtatCreature::EtatCreature(const string & nom) : nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_normal) {}

EtatCreature::EtatCreature(const string & nom, unsigned int duree) : nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_normal) {}

EtatCreature::~EtatCreature() {}

void EtatCreature::appliquerEtat(Creature & creature) {}

bool EtatCreature::peutAttaquer() const
{
	return rand() % 6 != 0;
}

bool EtatCreature::estFini() const
{
	return false;
}

string EtatCreature::getNom() const
{
	return nom_;
}

TypeEtat EtatCreature::getType() const
{
	return type_;
}

ostream & operator<<(ostream & os, const EtatCreature & etatCreature)
{
	os << "état" << etatCreature.nom_ << endl;

	return os;
}
