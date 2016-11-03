/**
*\ file : Pouvoir.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "Pouvoir.h"
#include <iostream>

Pouvoir::Pouvoir()
{
	type_ = TypeEtat_normal;
}

Pouvoir::Pouvoir(const string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire), type_(TypeEtat_normal)
{
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::getEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::getNom() const
{
	return nom_;
}

TypeEtat Pouvoir::getType() const
{
	return type_;
}

void Pouvoir::setNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::setEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::setNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Pouvoir::getNombreDeDegat() const
{
	return nombreDeDegat_;
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir)
{
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
	type_ = pouvoir.getType();
}

Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir)
{
	if (this != &pouvoir)
	{
		nom_ = pouvoir.nom_;
		nombreDeDegat_ = pouvoir.nombreDeDegat_;
		energieNecessaire_ = pouvoir.energieNecessaire_;
		type_ = pouvoir.getType();
	}
	return *this;
}

bool Pouvoir::operator==(const Pouvoir& pouvoir) const
{
	return (nom_ == pouvoir.nom_);
}

void Pouvoir::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	EtatCreature* etat_normal = new EtatCreature("TypeEtat_normal"); 
	creatureEnnemie.setEtat(etat_normal);
}

void Pouvoir::appliquerEffetDefensif(Creature & creatureAllie)
{
	EtatCreature* etat_normal = new EtatCreature("TypeEtat_normal");
	creatureAllie.setEtat(etat_normal);
}

ostream& operator<<(ostream& os, const Pouvoir& pouvoir)
{
	return os << pouvoir.nom_ << " possede un nombre de dégat de " << pouvoir.nombreDeDegat_ <<
		" et une energie necessaire de " << pouvoir.energieNecessaire_ << endl;
}
