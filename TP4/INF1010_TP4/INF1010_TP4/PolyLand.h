/**
*\ file : PolyLand.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#include <vector>
#include <iostream>

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(const std::string& nom);

	bool ajouterCreature(Creature* creature);
	bool retirerCreature(const std::string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const std::string nomCreature);

	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(Dresseur* dresseur);
	PolyLand& operator+=(Creature* creature);
	PolyLand& operator-=(Creature* creature);

	friend std::ostream& operator<<(std::ostream& os, const PolyLand& poly);

private:
	std::vector<Dresseur*> dresseurs_;
	std::vector<Creature*> creatures_;
};
#endif