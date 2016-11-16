/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: La cr�ature qui re�oit cette attaque perd de l'�nergie due au poison
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
	AttaqueMagiquePoison(); //MODIFI�
	AttaqueMagiquePoison(unsigned int duree); //MODIFI�
	virtual ~AttaqueMagiquePoison();

	virtual void appliquerAttaque(Creature& Creature); //MODIFI�

	virtual bool estFini() const;
	
	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea genNbAlea_;

};
#endif // !ETAT_EMPOISONNE_H

