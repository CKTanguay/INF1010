/**
*\ file : CreatureMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
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
* L'op�rateur surcharg� affiche les informations de l'�tat pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] creatureMagique Ce param�tre repr�sente la cr�ature magique dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{
	os << "La cr�ature Magique " << (Creature&)(creatureMagique);
	
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
* La fonction attaquer ci-dessous surcharge celle de la classe de base pour ajouter un bonus de vie � la cr�ature magique.
* \param [IN] pouvoir Ce param�tre repr�sente le avec lequel la cr�ature magique attaque.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature qui attaque et qui re�oit le bonus.
*/

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) 
{
	Creature::attaquer(pouvoir, creature);

	if ((getPointDeVieTotal() - getPointDeVie()) >= bonus_) {
		setPointDeVie(getPointDeVie()+ bonus_);
	}
}