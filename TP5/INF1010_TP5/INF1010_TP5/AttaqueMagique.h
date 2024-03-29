/**
*\ file : AttaqueMagique.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 21/11/16
*\ Cr�� le : 02/11/16
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>
#include "Creature.h"

class AttaqueMagique
{
public:
	AttaqueMagique(unsigned int duree) { duree_ = duree; }

	virtual ~AttaqueMagique() {} // � MODIFIER (si n�cessaire...)

	unsigned int obtenirDuree() const { return duree_; }
	void modifierDuree(unsigned int duree) { duree_ = duree; }

	virtual std::string obtenirTypeAttaque() const { return typeid(AttaqueMagique).name(); }

	virtual void appliquerAttaque(Creature& creature) = 0; //� appliquer sur la cr�ature qui poss�de ce pouvoir // � MODIFIER (si n�cessaire...)
	virtual bool estFini() const { return true;	} //si vrai, informe la cr�ature qu'elle peut retourner � l'�tat normal // � MODIFIER (si n�cessaire...)

	friend std::ostream& operator<<(std::ostream& o, const AttaqueMagique& attaqueMagique) // � MODIFIER (si n�cessaire...)
	{ 
		return o << "Attaque magique de type " << attaqueMagique.obtenirTypeAttaque() << " avec une dur�e de " << attaqueMagique.duree_ << std::endl;
	} 

protected:
	unsigned int duree_;
};
#endif




