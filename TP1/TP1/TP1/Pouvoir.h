/**
*\ file : Pouvoir.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <iostream>
#include <string>
using namespace std;
class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(string, int, int);
	~Pouvoir();

	void setNom(string);
	void setDegat(int);
	void setEnergieNeccessaire(int);

	string getNom() const;
	int getDegat() const;
	int getEnergieNeccessaire() const;
	void affichage();
private:
	string nom_;
	int degat_;
	int energieNeccessaire_;
};
#endif
