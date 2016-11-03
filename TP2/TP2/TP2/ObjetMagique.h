/**
*\ file : ObjetMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

using namespace std;

class ObjetMagique;
ostream& operator<<(ostream& os, const ObjetMagique& objetMagique);

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	friend ostream& operator<<(ostream& os, const ObjetMagique& objetMagique);

private:
	string nom_;
	int bonus_;
};

#endif
