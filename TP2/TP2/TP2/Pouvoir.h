/**
*\ file : Pouvoir.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <vector>

using namespace std;

class Pouvoir;
ostream& operator<<(ostream& os, const Pouvoir& pouvoir);

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	 string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const  string& nom);

	Pouvoir(const Pouvoir& pouvoir); // constructeur par copie

	void operator=(const Pouvoir& pouvoir);
	bool operator==(const Pouvoir& pouvoir);
	
	friend ostream& operator<<(ostream& os, const Pouvoir& pouvoir);

private:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
};
// creature ne partage  pas les powers (donc faire new et delete)
#endif