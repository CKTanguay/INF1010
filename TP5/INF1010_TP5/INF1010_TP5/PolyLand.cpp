/**
*\ file : PolyLand.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 21/11/16
*\ Cr�� le : 02/11/16
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
* La fonction permet tout simplement l'affichage d2 la liste de dresseurs en ordre alphab�tique de nom, 
* puis la liste de cr�atures en ordre croissant d'attaque.
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

	
