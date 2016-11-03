/**
*\ file : CreatureMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "Creature.h"

using namespace std;
class CreatureMagique : public Creature
{
public:
	CreatureMagique();
	CreatureMagique(const string& nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus);
	~CreatureMagique();
	CreatureMagique(CreatureMagique& creatureMagique);
	int getBonus() const;
	void setBonus(int bonus);
	void attaquer(const Pouvoir& pouvoir, Creature& creature);

	friend ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique);

private:
	int bonus_;
};