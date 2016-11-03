/**
*\ file : CreatureMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "CreatureMagique.h"

CreatureMagique::CreatureMagique() 
{
	bonus_ = 0;
}

CreatureMagique::CreatureMagique(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus) :Creature(nom, attaque, defense, pointDeVie, energie) 
{
	bonus_ = bonus;
}

CreatureMagique::~CreatureMagique() {};


/**
* L'opérateur surchargé affiche les informations de l'état passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] creatureMagique Ce paramètre représente la créature magique dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{
	os << "La créature Magique " << (Creature&)(creatureMagique);
	
	return os;
}


CreatureMagique::CreatureMagique(CreatureMagique& creatureMagique):Creature(creatureMagique) {
	bonus_ = creatureMagique.getBonus();
}


int CreatureMagique::getBonus()const {
	return bonus_;
}


void CreatureMagique::setBonus(int bonus) {
	bonus_ = bonus;
}


/**
* La fonction attaquer ci-dessous surcharge celle de la classe de base pour ajouter un bonus de vie à la créature magique.
* \param [IN] pouvoir Ce paramètre représente le avec lequel la créature magique attaque.
* \param [IN/OUT] creature Ce paramètre représente la créature qui attaque et qui reçoit le bonus.
*/

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) 
{
	Creature::attaquer(pouvoir, creature);

	if ((getPointDeVieTotal() - getPointDeVie()) >= bonus_) {
		setPointDeVie(getPointDeVie()+ bonus_);
	}
}