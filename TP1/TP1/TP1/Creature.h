/**
*\ file : Creature.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

#include "Pouvoir.h"

using namespace std;

#define NIVEAU_INITIAL 1
#define EXPERIENCE_NECESSAIRE 100


class Creature
{
public:
	Creature();
	Creature(string nom, int attaque, int defense, int pointDeVie, int energie, Pouvoir pouvoir);
	~Creature();
	string getNom() const;
	int getAttaque() const;
	int getDefense() const;
	int getPointDeVie() const;
	int getPointDeVieTotal() const;
	int getEnergie() const;
	int getEnergieTotal() const;
	int getExperience() const;
	int getExperienceNecessaire() const;
	int getNiveau() const;
	Pouvoir getPouvoir() const;

	void setNom(string);
	void setAttaque(int);
	void setDefense(int);
	void setPointDeVie(int);
	void setPointDeVieTotal(int);
	void setEnergie(int);
	void setEnergieTotal(int);
	void setExperience(int);
	void setExperienceNecessaire(int);
	void setNiveau(int);
	void setPouvoir(Pouvoir);
	void attaquer(Creature & creature);
	int experienceGagner(const Creature& creature);
	void information();

private:
	string nom_;
	int attaque_;
	int defense_;
	int pointDeVie_;
	int pointDeVieTotal_;
	int energie_;
	int energieTotal_;
	int experience_;
	int experienceNecessaire_;
	int niveau_;
	Pouvoir pouvoir_;
};
#endif