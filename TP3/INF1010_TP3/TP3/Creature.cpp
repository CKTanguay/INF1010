/**
*\ file : Creature.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "Creature.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Creature::Creature() :nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
energie_(0), experience_(0), niveau_(1)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
	etat_ = new EtatCreature("normal");
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie) :
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
	etat_ = new EtatCreature("normal");
}

Creature::~Creature()
{
	delete etat_;
}

string Creature::getNom() const
{
	return nom_;
}

unsigned int Creature::getAttaque() const
{
	return attaque_;
}

unsigned int Creature::getDefense() const
{
	return defense_;
}

unsigned int Creature::getPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::getPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::getEnergie() const
{
	return energie_;
}

unsigned int Creature::getEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::getExperience() const
{
	return experience_;
}

unsigned int Creature::getExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::getNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::getPouvoirs() const
{
	return pouvoirs_;
}

EtatCreature* Creature::getEtat()
{
	return etat_;
}


void Creature::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
	bool pouvoirEstDansVector = false;
	for (unsigned int i = 0; i < pouvoirs_.size(); i++) //S'assurer que votre cr�ature a bien ce pouvoir.
	{
		if (*pouvoirs_[i] == pouvoir)
		{
			pouvoirEstDansVector = true;
		}
	}
	if (energie_ >= pouvoir.getEnergieNecessaire() && pouvoirEstDansVector)
	{
		if (creature.getPointDeVie() >= 0) {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = abs((int)((pouvoir.getNombreDeDegat())* (attaque_ / 2 - creature.defense_)));
			int peutAttaquer = rand() % 6;
			if (peutAttaquer) {
				cout << nom_ << " lance " << pouvoir.getNom() << " qui inflige " << degat 
					<< " degat a " << creature.getNom() << endl;
				if (degat > creature.getPointDeVie()) {
					creature.setPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagn� " << xp << " XP" << endl;
				}
				else {
					creature.setPointDeVie(creature.getPointDeVie() - degat);
				}
					
				cout << creature.getNom() << " a encore " << creature.getPointDeVie() << " PV" << endl;
				energie_ -= pouvoir.getEnergieNecessaire();
			}
			else {
				cout << "La creature est dans " << *etat_ << endl;
				cout << "Attaque " << pouvoir.getNom() << " a �chou�e" << endl;
			}
		}
		else {
			cout << "Vous deja avez vaincu " << creature.getNom() << endl;
		}
	}
}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.getPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule 
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) * (creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

bool Creature::apprendrePouvoir(Pouvoir* pouvoir)
{
	for (unsigned int i = 0; i < pouvoirs_.size(); i++)
	{
		if (*pouvoirs_[i] == *pouvoir)
		{
			return false;
		}
	}
	pouvoirs_.push_back(pouvoir);
	return true;
}

bool Creature::oublierPouvoir(Pouvoir* pouvoir)
{
	for (unsigned int i = 0; i < pouvoirs_.size(); i++)
	{
		if (*(pouvoirs_[i]) == *pouvoir) 
		{
			pouvoirs_[i] = pouvoirs_.back();
			pouvoirs_.pop_back();
			cout << "Le pouvoir " << pouvoir->getNom() << " a bien ete retire." << endl;
			return true;
		}
	}
	cout << "Le pouvoir " << pouvoir->getNom() << " n'a pas ete retire." << endl;
	return false;
}

void Creature::setNom(const string& nom)
{
	nom_ = nom;
}

void Creature::setAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::setDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::setPointDeVie(unsigned int pointDeVie)
{
	if (pointDeVie >= 0) {
		pointDeVie_ = pointDeVie;
	}
}

void Creature::setEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::setExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::setNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::setPouvoirs(vector<Pouvoir*> pouvoirs)
{
	pouvoirs_ = pouvoirs;
}

void Creature::setEtat(EtatCreature* etat)
{
	delete etat_;
	etat_ = nullptr;
	etat_ = etat;
}

Creature::Creature(const Creature& creature)
{
	nom_ = creature.nom_;
	attaque_ = creature.attaque_;
	defense_ = creature.defense_;
	pointDeVie_ = creature.pointDeVie_;
	energie_ = creature.energie_;
	experience_ = creature.experience_;
	niveau_ = creature.niveau_;
	pouvoirs_ = creature.pouvoirs_;
}

Creature& Creature::operator=(const Creature& creature)
{
	if (this != &creature)
	{
		nom_ = creature.nom_;
		attaque_ = creature.attaque_;
		defense_ = creature.defense_;
		pointDeVie_ = creature.pointDeVie_;
		energie_ = creature.energie_;
		experience_ = creature.experience_;
		niveau_ = creature.niveau_;
		pouvoirs_ = creature.pouvoirs_;
	}

	return *this;
}

bool Creature::operator==(const Creature& creature) const
{
	return (nom_ == creature.nom_ && attaque_ == creature.attaque_ && defense_ == creature.defense_ && pointDeVie_ == creature.pointDeVie_
		&& pointDeVieTotal_ == creature.pointDeVieTotal_ && energie_ == creature.energie_ && energieTotal_ == creature.energieTotal_
		&& experience_ == creature.experience_ && experienceNecessaire_ == creature.experienceNecessaire_ && niveau_ == creature.niveau_);
}

bool Creature::operator==(const string& nom) const
{
	return (nom_ == nom);
}

void Creature::revenirEtatNormal()
{
	delete etat_;
	etat_ = new EtatCreature("normal");
}

bool operator==(const string& nom, const Creature& creature)
{
	return (creature == nom);
}

ostream& operator<<(ostream& os, const Creature& creature)
{
	os << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense, " << endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << endl
		<< "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << "d'XP" << endl
		<< "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau " << endl;
	os << "Pouvoirs : " << endl;
	if (!creature.pouvoirs_.empty()) {
		for (unsigned int i = 0; i < creature.pouvoirs_.size(); i++) {
			os << *(creature.pouvoirs_[i]);
		}
	}
	else
		os << creature.nom_ << " ne connait aucun pouvoir";
	os << endl;
	return os;
}