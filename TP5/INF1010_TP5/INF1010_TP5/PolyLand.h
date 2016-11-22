/**
*\ file : PolyLand.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "MondeMagique.h"
#include "Dresseur.h"
#include "Creature.h"
#include "Foncteur.h"
#include <vector>
#include <iostream>
using namespace std;

class PolyLand : public MondeMagique<Dresseur, Creature>
{
public:

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature);
	friend ostream& operator<<(std::ostream& os,PolyLand& polyland);
};
#endif