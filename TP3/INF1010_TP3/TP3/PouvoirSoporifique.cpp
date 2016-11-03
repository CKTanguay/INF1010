/**
*\ file : PouvoirSoporifique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "PouvoirSoporifique.h"

PouvoirSoporifique::PouvoirSoporifique() 
{
	type_ = TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) 
					:Pouvoir(nom, nombreDeDegat, energieNecessaire) 
{
	duree_ = duree;
	type_ = TypeEtat_endormi;
}

PouvoirSoporifique::~PouvoirSoporifique() {}


/**
* La fonction appliquerEffetOffensif ci-dessous surcharge celle de la classe de base pour appliquer l'effet d'un pouvoir sur
* la créature ennemie.
* \param [IN/OUT] creatureEnnemie Ce paramètre représente la créature ennemie sur laquelle on applique l'effet du pouvoir.
*/

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie) 
{
	if (creatureEnnemie.getEtat()->getType() != type_) {
		creatureEnnemie.setEtat(new EtatEndormi("endormi", duree_));
	}
}


/**
* L'opérateur surchargé affiche les informations du pouvoir passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] pouvoirSoporifique Ce paramètre représente le pouvoir dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const PouvoirSoporifique& pouvoirSoporifique)
{
	os << (Pouvoir&)(pouvoirSoporifique);
	os << "Il peut endormir la cible." << endl;
	return os;
}
