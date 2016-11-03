/**
*\ file : EtatEndormi.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include "EtatCreature.h"

using namespace std;

class EtatEndormi :public EtatCreature
{
public:
	EtatEndormi();
	EtatEndormi(const string& nom);
	EtatEndormi(const string& nom, unsigned int duree);
	~EtatEndormi();

	void appliquerEtat(Creature& creature); 
	bool peutAttaquer() const; 
	bool estFini() const; 

	friend ostream& operator<<(ostream& os, const EtatEndormi& etatEndormi);
};


#endif
