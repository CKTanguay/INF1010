/**
*\ file : CreatureMagique.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 01/11/16
*\ Cr�� le : 29/10/16
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
* L'op�rateur surcharg� modifie les attributs de la cr�ature courante en copiant ceux d'une cr�ature pass�e en param�tre.
* \param [IN] creatureMagique Ce param�tre repr�sente la cr�ature magique dont on copie les attributs.
* \return La fonction retourne la cr�ature courante par r�f�rence.
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
* La fonction obtenirTypeAttaque permet de retourner le type de la cr�ature.
* \return La valeur de retour de la fonction est une cha�ne de caract�res repr�sentant le type de la cr�ature.
*/

string CreatureMagique::obtenirTypeCreature() const
{
	return typeid(*this).name();
}


/**
* La fonction apprendreAttaqueMagique ajoute une attaque � une cr�ature magique.
* \param [IN] attaqueMagique Ce param�tre repr�sente l'attaque que la cr�ature doit apprendre.
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
* La fonction oublierAttaqueMagique retire une attaque � une cr�ature magique.
*/

void CreatureMagique::oublierAttaqueMagique() 
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}


/**
* L'op�rateur surcharg� affiche les informations de la cr�ature magique pass�e en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] creatureMagique Ce param�tre repr�sente l'attaque dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique) 
{
	os << static_cast<Creature>(creatureMagique) << "Cette cr�ature de la " << creatureMagique.obtenirTypeCreature() << " a aussi une attaque magique de type " << creatureMagique.obtenirAttaqueMagique()->obtenirTypeAttaque() <<
		" qui a une dur�e de " << creatureMagique.obtenirAttaqueMagique()->obtenirDuree() << endl;

	return os;
}


/**
* La fonction attaquer ci-dessous surcharge celle de la classe de base pour ajouter un bonus de vie � la cr�ature magique.
* \param [IN] pouvoir Ce param�tre repr�sente le avec lequel la cr�ature magique attaque.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature qui attaque et qui re�oit le bonus.
*/
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) 
{
	if (pointDeVie_ + bonus_ < pointDeVieTotal_)
		pointDeVie_ += bonus_;

	else
		pointDeVie_ = pointDeVieTotal_;

	cout << this->obtenirNom() << " s'est reg�n�r�" << endl;

	attaqueMagique_->appliquerAttaque(creature);

	Creature::attaquer(pouvoir, creature);
}