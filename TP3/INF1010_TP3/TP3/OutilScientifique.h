/**
*\ file : OutilScientifique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef OUTIL_SCIENTIFIQUE_H
#define OUTIL_SCIENTIFIQUE_H

#include <string>
#include "Creature.h"


using namespace std;

class OutilScientifique
{
public:
	OutilScientifique(const string& nom, const string& description);
	~OutilScientifique();

	string getNom() const;
	string getDescription() const;

	void setNom(const string& nom);
	void setDescription(const string& description);

	void utiliser(Creature& creature);

	friend ostream& operator<<(ostream& os, const OutilScientifique& outil);

private:
	string nom_;
	string description_;
};
#endif // !OUTIL_SCIENTIFIQUE_H


