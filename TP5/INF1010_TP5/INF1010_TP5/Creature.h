/**
*\ file : Creature.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 21/11/16
*\ Cr�� le : 02/11/16
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <typeinfo>

#include "Pouvoir.h"

class Creature
{
public:
	Creature();
	Creature(const std::string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);
	virtual ~Creature();
	
	std::string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	std::vector<Pouvoir*> obtenirPouvoirs() const;

	virtual void attaquer(const Pouvoir& pouvoir,Creature& creature);
	int experienceGagnee(const Creature& creature);

	bool apprendrePouvoir(Pouvoir* pouvoir);
	bool oublierPouvoir(Pouvoir* pouvoir);
	
	void modifierNom(const std::string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(std::vector<Pouvoir*> pouvoirs);

	Creature(const Creature& creature);
	Creature& operator=(const Creature& creature);

	bool operator==(const Creature& creature) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Creature& creature);

	friend std::ostream& operator<<(std::ostream& os, const Creature& creature); 

	virtual std::string obtenirTypeCreature() const;

	template<class PredicatBinaire>
	void trierPouvoirs(PredicatBinaire foncteur);

protected:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	std::vector<Pouvoir*> pouvoirs_;


	
};
/**
* La fonction trie le vecteur de pouvoirs selon la relation d�ordre induite par le pr�dicat.
* \param [IN] Un predicat Binaire
* \Aucune valeur de return
*/
template<class PredicatBinaire>
void Creature::trierPouvoirs(PredicatBinaire foncteur) {
	sort(pouvoirs_.begin(), pouvoirs_.end(), foncteur);
}
#endif
