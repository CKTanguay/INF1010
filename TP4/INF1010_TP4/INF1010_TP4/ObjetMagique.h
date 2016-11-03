/**
*\ file : ObjetMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/


#ifndef OBJET_MAGIQUE_H
#define OBJET_MAGIQUE_H

#include <string>
#include <iostream>


class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string &nom, int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	friend std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
