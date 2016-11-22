/**
*\ file : CreatureMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
*/
#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}


Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir)
{
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
}

Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir)
{
	if (this != &pouvoir)
	{
		nom_ = pouvoir.nom_;
		nombreDeDegat_ = pouvoir.nombreDeDegat_;
		energieNecessaire_ = pouvoir.energieNecessaire_;
	}
	return *this;
}

bool Pouvoir::operator==(const Pouvoir& pouvoir) const
{
	return (nom_ == pouvoir.nom_);
}

std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir)
{
	return os << pouvoir.nom_ << " possede un nombre de dégat de " << pouvoir.nombreDeDegat_ << " et une energie necessaire de " << pouvoir.energieNecessaire_ << std::endl;
}
