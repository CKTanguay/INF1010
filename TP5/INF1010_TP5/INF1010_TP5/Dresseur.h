/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#include "Creature.h"
#include "ObjetMagique.h"
#include "Foncteur.h"
using namespace std;
class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	auto obtenirCreatures() const;
	Creature* obtenirUneCreature(const std::string& nom) const; //À MODIFIFIER !!
	void modifierCreature(std::list<Creature*>  creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	void supprimerElements(PredicatUnaire foncteur);
	Creature* obtenirCreatureMax(PredicatUnaire foncteur);
	void obtenirCreatureMax(PredicatUnaire foncteur);
private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	list<Creature*> creatures_;
	

};
template<class PredicatUnaire>
void Dresseur::supprimerElements(PredicatUnaire foncteur) {
	creatures_ = erase_if(creatures_.begin(), creatures_.end(), fonteur); // p-e pas bon
}
template<class PredicatUnaire>
Creature* Dresseur::obtenirCreatureMax(PredicatUnaire foncteur) { // surment pas bon
	auto itr = max_element(creatures_.begin(), creatures_.end(), foncteur);
	return *itr;
}
template<class PredicatUnaire>
void Dresseur::obtenirCreatureMax(PredicatUnaire foncteur) {
	for_each(creatures_.begin(), creatures_.end(), foncteur);
}
#endif
