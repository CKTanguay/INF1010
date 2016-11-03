/**
*\ file : ObjetMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#ifndef OBJETMAGIQUE
#define OBJETMAGIQUE

#include <iostream>
#include <string>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(string nom, int bonus);
	~ObjetMagique();

	void setNom(string nom);
	void setBonus(int bonus);
	string getNom()const;
	int getBonus()const;
	void affichage();
private:
	string nom_;
	int bonus_;
};

#endif
