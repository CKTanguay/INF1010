/**
*\ file : PolyLand.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>       
#include "Creature.h"
#include "ObjetMagique.h"
#include "Dresseur.h"

using namespace std;

#define MAX_CREATURES 1000
#define MAX_DRESSEURS 100


class PolyLand
{
public:
	PolyLand();
	~PolyLand();

	bool addDresseur(Dresseur dresseur);
	bool removeDresseur(const string& nomDresseur);
	bool addCreature(Creature& creature);
	bool removeCreature(const string& nomCreature);
	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();
	bool attraperCreature(Dresseur& dresseur, Creature creature);
	bool relacherCreature(Dresseur& dresseur, string nomCreature);
	void infoDresseur(string nomDresseur);

private:
	Dresseur** dresseur_;
	int nbDresseur_;
	Creature** creature_;
	int nbCreature_;
};

#endif