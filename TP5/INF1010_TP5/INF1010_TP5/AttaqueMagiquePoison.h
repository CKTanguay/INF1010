/**
*\ file : AttaqueMagiquePoison.h
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 21/11/16
*\ Créé le : 02/11/16
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_POISON 2
#define RAND_MIN_DEFAUT 1
#define RAND_MAX_DEFAUT 6

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
	AttaqueMagiquePoison(); //MODIFIÉ
	AttaqueMagiquePoison(unsigned int duree); //MODIFIÉ
	virtual ~AttaqueMagiquePoison();

	virtual void appliquerAttaque(Creature& Creature); //MODIFIÉ

	virtual bool estFini() const;
	
	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea genNbAlea_;

};
#endif // !ETAT_EMPOISONNE_H

