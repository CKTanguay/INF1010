/**
*\ file : Creature.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"

using namespace std;

class Creature;
ostream& operator<<(ostream& os, const Creature& creature);
bool operator==(const string& nom, const Pouvoir& pouvoir);

class Creature
{
public:
	Creature(); // A MODIFIER... (si necessaire)
	Creature(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)
	~Creature(); // A MODIFIER... (si necessaire)

	Creature(const Creature& creature);

	bool operator==(const string& nomCreature);
	void operator=(const Creature& creature);
	bool operator==(const Creature& creature);
	friend bool operator==(const string& nom, const Pouvoir& pouvoir);
	friend ostream& operator<<(ostream& os, const Creature& creature);


	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	vector<Pouvoir*> obtenirPouvoirs() const; // A MODIFIER... (si necessaire)

	void attaquer(Pouvoir& pouvoir, Creature& creature);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);
	void modifierNom(const string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(const vector<Pouvoir*>& pouvoirs); // A MODIFIER... (si necessaire)

	bool apprendrePouvoir(const Pouvoir& pouvoir);
	bool oublierPouvoir(Pouvoir* nomPouvoir);

private:
	// creature composition dresseur on ne va pas baisser la vie de toutes les pikachou   donc new/delete     copier nouvelle creature dans polyland!!!
	// quand polyland creer les creatures elle donnes des copies au dresseur.
	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	vector<Pouvoir*> pouvoirs_;
	
};

#endif