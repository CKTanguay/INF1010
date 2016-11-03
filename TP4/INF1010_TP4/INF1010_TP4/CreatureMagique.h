/**
*\ file : CreatureMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "Creature.h"
#include "AttaqueMagique.h"
#include "AttaqueMagiquePoison.h"
#include "AttaqueMagiqueConfusion.h"

using namespace std;

class CreatureMagique : public Creature 
{
public:
	CreatureMagique();
	CreatureMagique(int bonus, Creature& creature);
	virtual ~CreatureMagique();
	CreatureMagique(const CreatureMagique& creatureMagique);
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

	void modifierBonus(int bonus);
	int obtenirBonus() const;
	void modifierAttaqueMagique(AttaqueMagique* attaqueMagique);
	AttaqueMagique* obtenirAttaqueMagique() const;
	void apprendreAttaqueMagique(AttaqueMagique* attaqueMagique);
	void oublierAttaqueMagique();
	virtual string obtenirTypeCreature() const;


	friend ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique);
	virtual void attaquer(const Pouvoir& pouvoir, Creature& creature);

private:
	AttaqueMagique* attaqueMagique_;
	int bonus_;

};



#endif