/**
*\ file : Professeur.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <iostream>
#include <string>
#include "Dresseur.h"
#include "OutilScientifique.h"


using namespace std;

class Professeur :public Dresseur
{
public:
	Professeur();
	Professeur(const string& nomProfesseur, const string& equipe);
	~Professeur();

	Professeur(const Professeur& professeur); //constructeur par copie

	OutilScientifique* getOutilScientifique() const;
	void setOutilScientifique(OutilScientifique& outilScientifique); //peut etre ajouter un const dans le futur

	void soigner(Creature& creature); //peut etre passer un pointeur.

	void operator=(OutilScientifique& outilScientifique2);

	friend ostream& operator<<(ostream& os, const Professeur& professeur);

private:
	OutilScientifique* outilScientifique_;

};

#endif
