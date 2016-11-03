/**
*\ file : Dresseur.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <iostream>
#include <string>
#include "Creature.h"
#include "ObjetMagique.h"

using namespace std;

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur();
	Dresseur(const string& nom);
	~Dresseur();

	string getNom() const;
	void setNom(const string& nom);

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

	void useObjetMagique(Creature* creature);

	unsigned int getNombreCreatures() const;

	Creature** getCreatures() const;
	void setCreature(Creature** creatures);

	bool addCreature(const Creature& creature);
	bool removeCreature(const string& nom);

	void affichage() const;

private:
	string nom_;

	Creature** creatures_;

	unsigned int nombreCreatures_;
	unsigned int nombreCreaturesMax_;
	ObjetMagique objetMagique_;

};

#endif