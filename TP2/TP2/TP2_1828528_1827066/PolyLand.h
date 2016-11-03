/**
*\ file : PolyLand.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

using namespace std;

class PolyLand;
ostream& operator<<(ostream& os, const PolyLand& polyland);

class PolyLand
{
public:
	PolyLand(); 
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur); // A MODIFIER... (si necessaire) // -*
	bool ajouterCreature(const Creature* creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const  string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const  string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire() const; 
	Creature* choisirCreatureAleatoire() const;

	bool attraperCreature(Dresseur* dresseur, const Creature* creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const  string& nomCreature); // A MODIFIER... (si necessaire)
	
	PolyLand& operator+=( Dresseur* dresseur);
	PolyLand& operator-=(const Dresseur* dresseur);
	PolyLand& operator+=(const Creature* creature);
	PolyLand& operator-=(const Creature* creature);
	friend ostream& operator<<(ostream& os, const PolyLand& polyland);

private:
	vector<Dresseur*> dresseurs_;
	vector<Creature*> creatures_;

};
#endif