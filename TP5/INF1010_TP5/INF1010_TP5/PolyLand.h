/*
Fichier: PolyLand.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: Polyland represente le pays que l'on va explorer, il va contenir
			les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "MondeMagique.h"
#include "Dresseur.h"
#include "Creature.h"
#include <vector>
#include <iostream>

//template ici
class PolyLand : public MondeMagique<Dresseur, Creature>
{
public:

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature);

};
#endif