/**
*\ file : Dresseur.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <iostream>
#include <vector>

using namespace std;

class Dresseur
{
public:
	Dresseur();
	Dresseur(const string& nom, const string& equipe);
	~Dresseur();

	//constr copie

	string getNom() const;
	void setNom(const string& nom);
	
	unsigned int getNombreCreatures() const;

	vector<Creature*> getCreatures() const;
	Creature* getUneCreature(const string& nom) const;
	void setCreature(vector<Creature*> creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const string& nom);

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	string getEquipe() const;
	void setEquipe(const string& equipe);

	friend ostream& operator<<(ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const string& nom) const;
	friend bool operator==(const string& nom, const Dresseur& dresseur);

private:
	string nom_;
	vector<Creature*> creatures_;
	string equipe_;
	ObjetMagique* objetMagique_;


};

#endif