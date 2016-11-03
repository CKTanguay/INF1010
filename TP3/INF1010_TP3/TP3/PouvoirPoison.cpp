/**
*\ file : PouvoirPoison.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "PouvoirPoison.h"

PouvoirPoison::PouvoirPoison() 
{
	type_ = TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) 
{
	type_ = TypeEtat_empoisonne;
}

PouvoirPoison::~PouvoirPoison() {}


/**
* La fonction appliquerEffetOffensif ci-dessous surcharge celle de la classe de base pour appliquer l'effet d'un pouvoir sur
* la cr�ature ennemie.
* \param [IN/OUT] creatureEnnemie Ce param�tre repr�sente la cr�ature ennemie sur laquelle on applique l'effet du pouvoir.
*/

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	if (creatureEnnemie.getEtat()->getType() != type_){
		creatureEnnemie.setEtat(new EtatEmpoisonne("empoisonne", duree_));
	}
}


/**
* L'op�rateur surcharg� affiche les informations du pouvoir pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] pouvoirPoison Ce param�tre repr�sente le pouvoir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const PouvoirPoison& pouvoirPoison)
{
	os << (Pouvoir&)(pouvoirPoison);
	os << "Il peut empoisonner la cible." << endl;
	return os;
}
