/**
*\ file : EtatCreature.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"

using namespace std;

//déclaration anticipée nécessaire à cause des inclusions circulaires
class Creature;

class EtatCreature
{
public:
	EtatCreature();
	EtatCreature(const string& nom);
	EtatCreature(const string& nom, unsigned int duree);
	~EtatCreature();

	void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
	bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer
	bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

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




