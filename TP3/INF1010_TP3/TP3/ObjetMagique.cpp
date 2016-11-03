/**
*\ file : ObjetMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

string ObjetMagique::getNom() const
{
	return nom_;
}

int ObjetMagique::getBonus() const
{
	return bonus_;
}

void ObjetMagique::setNom(const string& nom)
{
	nom_ = nom;
}

void ObjetMagique::setBonus(int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::utiliserSur(Creature & creature) const
{
	if ((creature.getPointDeVieTotal() - creature.getPointDeVie()) >= getBonus()) {
		creature.setPointDeVie(creature.getPointDeVie() + getBonus());
	}
	else {
		creature.setPointDeVie(creature.getPointDeVieTotal());
	}
	if ((creature.getEnergieTotale() - creature.getEnergie()) > getBonus()) {
		creature.setEnergie(creature.getEnergie() + getBonus());
	}
	else {
		creature.setEnergie(creature.getEnergieTotale());
	}
}

ostream& operator<<(ostream& os, const ObjetMagique& objet)
{
	return os << "l'objet " << objet.nom_ << "fournit un bonus de " << objet.bonus_ << endl;
}
