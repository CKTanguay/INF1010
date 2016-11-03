/**
*\ file : EtatEmpoisonne.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

using namespace std;

class EtatEmpoisonne : public EtatCreature
{
public:
	EtatEmpoisonne();
	EtatEmpoisonne(const string& nom);
	EtatEmpoisonne(const string& nom, unsigned int duree);
	~EtatEmpoisonne();

	void appliquerEtat(Creature& creature);
	bool estFini() const; 
	
	friend ostream& operator<<(ostream& os, const EtatEmpoisonne& etatEmpoisonne);
};

#endif
