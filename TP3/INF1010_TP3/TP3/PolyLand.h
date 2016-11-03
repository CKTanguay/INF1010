/**
*\ file : PolyLand.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include <vector>
#include <iostream>

#include "Dresseur.h"
#include "Creature.h"

using namespace std;

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(const string& nom);

	bool ajouterCreature(Creature* creature);
	bool retirerCreature(const string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const string nomCreature);

	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(Dresseur* dresseur);
	PolyLand& operator+=(Creature* creature);
	PolyLand& operator-=(Creature* creature);

	friend ostream& operator<<(ostream& os, const PolyLand& poly);

private:
	vector<Dresseur*> dresseurs_;
	vector<Creature*> creatures_;
};
#endif