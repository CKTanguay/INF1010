/**
*\ file : CreatureMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 01/11/16
*\ Créé le : 29/10/16
*/

#include "CreatureMagique.h"

using namespace std;

CreatureMagique::CreatureMagique() :Creature() 
{
	bonus_ = 0;
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(int bonus, Creature& creature) : Creature(creature.obtenirNom(), creature.obtenirAttaque(),
	creature.obtenirDefense(), creature.obtenirPointDeVie(), creature.obtenirEnergie()) 
{
	bonus_ = bonus;
	attaqueMagique_ = nullptr;
}

CreatureMagique::~CreatureMagique() 
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique) 
{
	nom_ = creatureMagique.obtenirNom();
	attaque_= creatureMagique.obtenirAttaque();
	defense_= creatureMagique.obtenirDefense();
	pointDeVie_ =creatureMagique.obtenirPointDeVie();
	pointDeVieTotal_= creatureMagique.obtenirPointDeVieTotal();
	energie_= creatureMagique.obtenirEnergie();
	energieTotal_= creatureMagique.obtenirEnergieTotale();
	experience_= creatureMagique.obtenirExperience();
	experienceNecessaire_= creatureMagique.obtenirExperienceNecessaire();
	niveau_= creatureMagique.obtenirNiveau();
	pouvoirs_= creatureMagique.obtenirPouvoirs();
	apprendreAttaqueMagique(creatureMagique.obtenirAttaqueMagique());
}


/**
* L'opérateur surchargé modifie les attributs de la créature courante en copiant ceux d'une créature passée en paramètre.
* \param [IN] creatureMagique Ce paramètre représente la créature magique dont on copie les attributs.
* \return La fonction retourne la créature courante par référence.
*/

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique) 
{
	nom_ = creatureMagique.obtenirNom();
	attaque_ = creatureMagique.obtenirAttaque();
	defense_ = creatureMagique.obtenirDefense();
	pointDeVie_ = creatureMagique.obtenirPointDeVie();
	pointDeVieTotal_ = creatureMagique.obtenirPointDeVieTotal();
	energie_ = creatureMagique.obtenirEnergie();
	energieTotal_ = creatureMagique.obtenirEnergieTotale();
	experience_ = creatureMagique.obtenirExperience();
	experienceNecessaire_ = creatureMagique.obtenirExperienceNecessaire();
	niveau_ = creatureMagique.obtenirNiveau();
	apprendreAttaqueMagique(creatureMagique.obtenirAttaqueMagique());

	for (int i = 0; i < creatureMagique.pouvoirs_.size(); i++)
	{
		pouvoirs_.push_back(new Pouvoir(*creatureMagique.obtenirPouvoirs()[i]));
	}
	return *this;
}


void CreatureMagique::modifierBonus(int bonus) 
{
	bonus_ = bonus;
}

int CreatureMagique::obtenirBonus()const 
{
	return bonus_;
}

void CreatureMagique::modifierAttaqueMagique(AttaqueMagique* attaqueMagique) 
{
	apprendreAttaqueMagique(attaqueMagique);
}

AttaqueMagique* CreatureMagique::obtenirAttaqueMagique()const 
{
	return attaqueMagique_;
}


/**
* La fonction obtenirTypeAttaque permet de retourner le type de la créature.
* \return La valeur de retour de la fonction est une chaîne de caractères représentant le type de la créature.
*/

string CreatureMagique::obtenirTypeCreature() const
{
	return typeid(*this).name();
}


/**
* La fonction apprendreAttaqueMagique ajoute une attaque à une créature magique.
* \param [IN] attaqueMagique Ce paramètre représente l'attaque que la créature doit apprendre.
*/

void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique) 
{
	delete attaqueMagique_;

	if (typeid(AttaqueMagiquePoison).name() == attaqueMagique->obtenirTypeAttaque()) 
	{ 
		attaqueMagique_ = new AttaqueMagiquePoison;
		attaqueMagique_ = attaqueMagique;
	}

	else if(typeid(AttaqueMagiqueConfusion).name() == attaqueMagique->obtenirTypeAttaque()) 
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion;
		attaqueMagique_ = attaqueMagique;
	}
}


/**
* La fonction oublierAttaqueMagique retire une attaque à une créature magique.
*/

void CreatureMagique::oublierAttaqueMagique() 
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}


/**
* L'opérateur surchargé affiche les informations de la créature magique passée en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] creatureMagique Ce paramètre représente l'attaque dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique) 
{
	os << static_cast<Creature>(creatureMagique) << "Cette créature de la " << creatureMagique.obtenirTypeCreature() << " a aussi une attaque magique de type " << creatureMagique.obtenirAttaqueMagique()->obtenirTypeAttaque() <<
		" qui a une durée de " << creatureMagique.obtenirAttaqueMagique()->obtenirDuree() << endl;

	return os;
}


/**
* La fonction attaquer ci-dessous surcharge celle de la classe de base pour ajouter un bonus de vie à la créature magique.
* \param [IN] pouvoir Ce paramètre représente le avec lequel la créature magique attaque.
* \param [IN/OUT] creature Ce paramètre représente la créature qui attaque et qui reçoit le bonus.
*/
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) 
{
	if (pointDeVie_ + bonus_ < pointDeVieTotal_)
		pointDeVie_ += bonus_;

	else
		pointDeVie_ = pointDeVieTotal_;

	cout << this->obtenirNom() << " s'est regénéré" << endl;

	attaqueMagique_->appliquerAttaque(creature);

	Creature::attaquer(pouvoir, creature);
}