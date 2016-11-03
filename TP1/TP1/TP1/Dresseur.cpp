/**
*\ file : Dresseur.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include "Dresseur.h"
#include <clocale>  // pour setlocale


Dresseur::Dresseur()
{
	nom_ = "";
	*creatures_ = new Creature[MAX_NOMBRE_CREATURES];
	for (int i = 0; i < MAX_NOMBRE_CREATURES; i++)
	{
		creatures_[i] = nullptr;
	}
	nombreCreatures_ = 0;
	nombreCreaturesMax_ = MAX_NOMBRE_CREATURES;
}

Dresseur::Dresseur(const string& nom)
{
	nom_ = nom;
}

Dresseur::~Dresseur()
{
	for (int i = 0; i < nombreCreatures_; i++)
		creatures_[i] = nullptr;
	delete[] creatures_;
}

#pragma region GET/SET

string Dresseur::getNom() const
{
	return nom_;
}

void Dresseur::setNom(const string& nom)
{
	nom_ = nom;
}

ObjetMagique Dresseur::getObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::setObjetMagique(const ObjetMagique& objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::useObjetMagique(Creature* creature)
{
	if (creature->getPointDeVie() <= creature->getPointDeVieTotal() - objetMagique_.getBonus())
	{
		creature->setPointDeVie(creature->getPointDeVie() + objetMagique_.getBonus());
	}

	else if (creature->getPointDeVie() > creature->getPointDeVieTotal() - objetMagique_.getBonus())
	{
		creature->setPointDeVie(creature->getPointDeVieTotal());
	}

	if (creature->getEnergie() <= creature->getEnergieTotal() - objetMagique_.getBonus())
	{
		creature->setEnergie(creature->getEnergie() + objetMagique_.getBonus());
	}

	else if (creature->getEnergie() > creature->getEnergieTotal() - objetMagique_.getBonus())
	{
		creature->setPointDeVie(creature->getEnergieTotal());
	}
}

unsigned int Dresseur::getNombreCreatures() const
{
	return nombreCreatures_;
}

Creature** Dresseur::getCreatures() const
{
	return creatures_;
}

void Dresseur::setCreature(Creature** creatures)
{
	creatures_ = creatures;
}

#pragma endregion


/**
* La fonction ajoute une nouvelle créature dans le tableau si elle n'y est pas déjà.
* \param [IN/OUT] creature Ce paramètre représente la créature qui est ajoutée au tableau. Elle est de type const, donc
même si elle est passée en référence, elle ne peut pas être modifiée.
* \return La valeur de retour de la fonction est true si l'ajout a bien été fait et false dans le cas contraire.
*/

bool Dresseur::addCreature(const Creature& creature)
{
	for (unsigned int j = 0; j < nombreCreatures_; j++)
	{
		if ((creatures_[j])->getNom() == creature.getNom())
			return false; // sortir de addCreature
	}

	if (nombreCreaturesMax_ == nombreCreatures_)
	{
		//nombreCreaturesMax_ *= 2;

		Creature** creaturesTemp; // pas besoin de delete, car il a son destructrur par default
		creaturesTemp = new Creature*[(nombreCreatures_ * 2)];

		for (int i = 0; i < (nombreCreaturesMax_); i++)
		{
			creaturesTemp[i] = creatures_[i];
			creatures_[i] = nullptr;
		}

		delete[] creatures_;
		creatures_ = creaturesTemp;
		creatures_[nombreCreatures_] = new  Creature(creature);
		nombreCreaturesMax_ = nombreCreaturesMax_ * 2;
		nombreCreatures_++;

	}


	return true;
}


/**
* La fonction retire une créature du tableau de créatures si elle s'y trouve.
* \param [IN/OUT] creature Ce paramètre représente la créature qui est retirée du tableau. Elle est de type const, donc
même si elle est passée en référence, elle ne peut pas être modifiée.
* \return La valeur de retour de la fonction est true si le retrait a bien été fait et false dans le cas contraire.
*/

bool Dresseur::removeCreature(const string& nom)
{
	if ((--nombreCreatures_) * 2 > nombreCreaturesMax_)
	{
		int positionCreature = 0;

		for (int i = 0; i < nombreCreatures_; i++)
		{
			if ((creatures_[i])->getNom() == nom)
				positionCreature = i;
		}

		for (positionCreature; positionCreature < nombreCreatures_; positionCreature++)
		{
			creatures_[positionCreature] = creatures_[++positionCreature];
		}

		nombreCreatures_--;
		creatures_[nombreCreatures_] = nullptr;
		delete creatures_[nombreCreatures_];
		return true;
	}

	else if ((--nombreCreatures_) * 2 == nombreCreaturesMax_)////retirer creature, copier celle a la fin et deleter derniere case
	{
		Creature** creaturesTemp;
		nombreCreaturesMax_ = nombreCreaturesMax_ / 2;
		creaturesTemp = new Creature*[(nombreCreaturesMax_)];
		int positionCreature = 0;

		for (int i = 0; i < nombreCreatures_; i++)
		{
			if ((creatures_[i])->getNom() == nom)
				positionCreature = i;
		}

		for (int i = 0; i < (--nombreCreaturesMax_); i++)
		{
			if (i != positionCreature)
				creaturesTemp[i] = creatures_[i];
			creatures_[i] = nullptr;
		}
		delete[] creatures_;
		creatures_ = creaturesTemp;
		nombreCreatures_--;
		return true;
	}

	else return false;
}


/**
* La fonction permet tout simplement l'affichage des informations sur la créature.
*/

void Dresseur::affichage() const
{
	setlocale(LC_ALL, "");

	cout << nom_ << " possede " << nombreCreatures_ << " creature(s)." << endl;
}

