/**
*\ file : Dresseur.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

using namespace std;

class Dresseur;
bool operator== (const string& nom, const Dresseur& dresseur);
ostream& operator<<(ostream& os, const Dresseur& DresseurAfficher);

class Dresseur
{
public:
	Dresseur(); 
	Dresseur(const string& nom, const string& equipe); 
	~Dresseur(); 

	bool operator== (const Dresseur& dresseur2) const;
	bool operator==(const string& nomDresseur) const;
	friend ostream& operator<<(ostream& os, const Dresseur& DresseurAfficher);
	friend bool operator== (const string& nom, const Dresseur& dresseur);

	string obtenirNom() const;
	void modifierNom(const string& nom);
	
	unsigned int obtenirNombreCreatures() const; 

	Creature* obtenirUneCreature(const string& nom) const; 
	void modifierCreature(const vector<Creature*>& creatures);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	string obtenirEquipe() const;
	void modifierEquipe(const string equipe);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(const Creature* creature); 
	bool enleverCreature(const string& nom); 


private:
	string nom_;
	ObjetMagique objetMagique_;
	vector<Creature*> creatures_;
	string equipe_;
};

#endif