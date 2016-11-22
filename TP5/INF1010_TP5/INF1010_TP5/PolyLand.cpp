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
/**
* La fonction permet tout simplement l'affichage d2 la liste de dresseurs en ordre alphabétique de nom, 
* puis la liste de créatures en ordre croissant d'attaque.
*/
ostream& operator<<(std::ostream& os, PolyLand& polyland)
{
	
	polyland.listMaitre_.sort(FoncteurComparerDresseurs());
	for (auto it = polyland.listMaitre_.begin(); it != polyland.listMaitre_.end(); it++) {
		cout << **it << endl;
	}

	polyland.listCompagnon_.sort(FoncteurComparerCreatures()); {
		for (auto it = polyland.listCompagnon_.begin(); it != polyland.listCompagnon_.end(); it++)
			cout << **it << endl;
	}
	return os;
	
}

	
