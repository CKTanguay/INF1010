/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}
ostream& operator<<(std::ostream& os, const PolyLand& polyland)
{
	sort(polyland.listCompagnon_.begin(), polyland.listCompagnon_.end(), FoncteurComparerCreatures());
	sort(polyland.listMaitre_.begin(), polyland.listMaitre_.end(), FoncteurComparerDresseurs());

	return os;
}

	
