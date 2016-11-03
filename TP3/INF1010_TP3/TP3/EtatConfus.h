/**
*\ file : EtatConfus.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"

using namespace std;

class EtatConfus :public EtatCreature
{
public:
	EtatConfus();
	EtatConfus(const string& nom);
	EtatConfus(const string& nom, unsigned int duree);
	~EtatConfus();

	bool peutAttaquer() const;
	void appliquerEtat(Creature& creature);
	bool estFini() const;


	friend ostream& operator<<(ostream& os, const EtatConfus& etatConfus);
};
#endif
