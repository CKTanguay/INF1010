/**
*\ file : EtatCreature.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"

using namespace std;

//d�claration anticip�e n�cessaire � cause des inclusions circulaires
class Creature;

class EtatCreature
{
public:
	EtatCreature();
	EtatCreature(const string& nom);
	EtatCreature(const string& nom, unsigned int duree);
	~EtatCreature();

	void appliquerEtat(Creature& creature); //� appliquer sur la cr�ature qui poss�de ce pouvoir
	bool peutAttaquer() const; //d�termine si l'�tat de la cr�ature lui permet d'attaquer
	bool estFini() const; //si vrai, informe la cr�ature qu'elle peut retourner � l'�tat normal

	string getNom() const;
	TypeEtat getType() const;

	friend ostream& operator<<(ostream& o, const EtatCreature& etatCreature);

private:
	string nom_;

protected:
	unsigned int duree_;
	TypeEtat type_;
};
#endif // !ETAT_CREATURE_H




