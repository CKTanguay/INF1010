/**
*\ file : AttaqueMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>
#include "Creature.h"

class AttaqueMagique
{
public:
	AttaqueMagique(unsigned int duree) { duree_ = duree; }

	virtual ~AttaqueMagique() {} // À MODIFIER (si nécessaire...)

	unsigned int obtenirDuree() const { return duree_; }
	void modifierDuree(unsigned int duree) { duree_ = duree; }

	virtual std::string obtenirTypeAttaque() const { return typeid(AttaqueMagique).name(); }

	virtual void appliquerAttaque(Creature& creature) = 0; //à appliquer sur la créature qui possède ce pouvoir // À MODIFIER (si nécessaire...)
	virtual bool estFini() const { return true;	} //si vrai, informe la créature qu'elle peut retourner à l'état normal // À MODIFIER (si nécessaire...)

	friend std::ostream& operator<<(std::ostream& o, const AttaqueMagique& attaqueMagique) // À MODIFIER (si nécessaire...)
	{ 
		return o << "Attaque magique de type " << attaqueMagique.obtenirTypeAttaque() << " avec une durée de " << attaqueMagique.duree_ << std::endl;
	} 

protected:
	unsigned int duree_;
};
#endif




