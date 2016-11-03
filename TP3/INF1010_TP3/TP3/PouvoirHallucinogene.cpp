/**
*\ file : PouvoirHallucinogene.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "PouvoirHallucinogene.h"

PouvoirHallucinogene::PouvoirHallucinogene() 
{
	type_ = TypeEtat_confus;
}

PouvoirHallucinogene::PouvoirHallucinogene(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) 
					:Pouvoir(nom, nombreDeDegat, energieNecessaire) 
{
	duree_ = duree;
	type_ = TypeEtat_confus;
}

PouvoirHallucinogene::~PouvoirHallucinogene() {}


/**
* La fonction appliquerEffetOffensif ci-dessous surcharge celle de la classe de base pour appliquer l'effet d'un pouvoir sur 
* la cr�ature ennemie.
* \param [IN/OUT] creatureEnnemie Ce param�tre repr�sente la cr�ature ennemie sur laquelle on applique l'effet du pouvoir.
*/

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie) 
{
	if (creatureEnnemie.getEtat()->getType() != type_){
		creatureEnnemie.setEtat(new EtatConfus("confus", duree_));
	}
}


/**
* L'op�rateur surcharg� affiche les informations du pouvoir pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] pouvoirHallucinogene Ce param�tre repr�sente le pouvoir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene)
{
	os << (Pouvoir&)(pouvoirHallucinogene);
	os << "Il peut rendre la cible confuse." << endl;
	return os;
}
