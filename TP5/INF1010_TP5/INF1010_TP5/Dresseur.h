/**
*\ file : Dresseur.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
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
//#include "Foncteur.h"
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

	template<typename PredicatUnaire>
	void supprimerElement(PredicatUnaire foncteur);

	template<typename PredicatUnaire>
	Creature* obtenirCreatureMax(PredicatUnaire foncteur);

	template<typename PredicatUnaire>
	void appliquerFoncteurUnaire(PredicatUnaire& foncteur);

private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	list<Creature*> creatures_;
	

};

/**
* La fonction supprime tous les éléments du conteneur pour lesquels l’application du foncteur passé en argument retourne true
* \param [IN] Un predicat Unaire
* \Aucune valeur de return
*/
template<class PredicatUnaire>
void Dresseur::supprimerElement(PredicatUnaire foncteur) 
{
	creatures_.remove_if(foncteur);
}

/**
* La fonction retourne la créature max selon l’ordre induit par le foncteur
* \param [IN] Un predicat Unaire
* \Return: Creature* un pointeur vers la créature qui correspond à l'ordre du foncteur 
*/
template<class PredicatUnaire>
Creature* Dresseur::obtenirCreatureMax(PredicatUnaire foncteur) 
{
	auto itr = max_element(creatures_.begin(), creatures_.end(), foncteur);
	return *itr;
}

/**
* La fonction applique le foncteur à toutes les créatures du conteneur
* \param [IN] Un predicat Unaire
* \Aucune valeur de return
*/
template<class PredicatUnaire>
void Dresseur::appliquerFoncteurUnaire(PredicatUnaire& foncteur) 
{
	foncteur = for_each(creatures_.begin(), creatures_.end(), foncteur);
}
#endif
