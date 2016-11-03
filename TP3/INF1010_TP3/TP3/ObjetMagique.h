/**
*\ file : ObjetMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

#include "Creature.h"

using namespace std;

class Creature;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string getNom() const;
	int getBonus() const;

	void setNom(const string& nom);
	void setBonus(int bonus);

	void utiliserSur(Creature& creature) const;

	friend ostream& operator<<(ostream& os, const ObjetMagique& objet);

private:
	string nom_;
	int bonus_;
};

#endif
