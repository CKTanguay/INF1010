/**
*\ file : AttaqueMagiqueConfusion.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 21/11/16
*\ Cr�� le : 02/11/16
*/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include <stdlib.h>

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_CONFUSION 3

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
	AttaqueMagiqueConfusion(); // � MODIFIER
	AttaqueMagiqueConfusion(unsigned int duree); // � MODIFIER
	virtual ~AttaqueMagiqueConfusion(); 

	virtual void appliquerAttaque(Creature& Creature); // � MODIFIER

	virtual bool estFini() const;

	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea genNbAlea_;

};
#endif 




