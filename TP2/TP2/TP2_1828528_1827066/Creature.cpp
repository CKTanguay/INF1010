/**
*\ file : Creature.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0), energie_(0), experience_(0), niveau_(1) 
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const string& nom, unsigned int attaque,	unsigned int defense, unsigned int pointDeVie, unsigned int energie) :
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie), energie_(energie), experience_(0), niveau_(1) 
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::~Creature()
{
	for (unsigned int i = 0; i < pouvoirs_.size(); i++)
	{
		delete pouvoirs_[i];
		pouvoirs_[i] = nullptr;
	}
}


/**
* La fonction construit une créature identique à celle passée en paramètre
* \param [IN] creature Ce paramètre représente la créature à copier.
* \return La fonction retourne la créature qui a été construite.
*/

Creature::Creature(const Creature& creature) {
	nom_ = creature.obtenirNom();
	attaque_ = creature.obtenirAttaque();
	defense_ = creature.obtenirDefense();
	pointDeVie_ = creature.obtenirPointDeVie();
	pointDeVieTotal_ = creature.obtenirPointDeVieTotal();
	energie_ = creature.obtenirEnergie();
	energieTotal_ = creature.obtenirEnergieTotale();
	experience_ = creature.obtenirExperience();
	experienceNecessaire_ = creature.obtenirExperienceNecessaire();
	niveau_ = creature.obtenirNiveau();

	for (int i = 0; i < (creature.obtenirPouvoirs()).size(); i++) {
		pouvoirs_.push_back(new Pouvoir(*creature.obtenirPouvoirs()[i])); // aucune idee si sa marche xd
	}
}


/**
* L'opérateur surchargé vérifie que le nom de la créature courante est identique au nom en paramètre.
* \param [IN] nomCreature Ce paramètre représente le nom de la créature qui est à comparer.
* \return La valeur de retour de la fonction est true si les noms sont identiques et false sinon.
*/

bool Creature::operator==(const string& nomCreature) 
{
	return(nom_ == nomCreature);
}


/**
* L'opérateur permet de créer une créature en copiant celle passée en paramètre.
* \param [IN] creature Ce paramètre représente la créature à copier.
*/

void Creature::operator=(const Creature& creature) {
	nom_ = creature.obtenirNom();
	attaque_ = creature.obtenirAttaque();
	defense_ = creature.obtenirDefense();
	pointDeVie_ = creature.obtenirPointDeVie();
	pointDeVieTotal_ = creature.obtenirPointDeVieTotal();
	energie_ = creature.obtenirEnergie();
	energieTotal_ = creature.obtenirEnergieTotale();
	experience_ = creature.obtenirExperience();
	experienceNecessaire_ = creature.obtenirExperienceNecessaire();
	niveau_ = creature.obtenirNiveau();

	for (int i = 0; i < (creature.obtenirPouvoirs()).size(); i++) {
		pouvoirs_.push_back(new Pouvoir(*creature.obtenirPouvoirs()[i]));
	}
}


/**
* L'opérateur surchargé vérifie que tous les attributs de deux créatures sont identiques, sauf pour les pouvoirs.
* \param [IN] creature Ce paramètre représente la créature qui est à comparer.
* \return La valeur de retour de la fonction est true si les attributs sont identiques et false sinon.
*/

bool Creature::operator==(const Creature& creature) 
{
	int nbAtributPareil = 0;

	if (nom_ == creature.obtenirNom())
		nbAtributPareil++;

	if(attaque_ == creature.obtenirAttaque())
		nbAtributPareil++;

	if (defense_ == creature.obtenirDefense())
		nbAtributPareil++;

	if(pointDeVie_ == creature.obtenirPointDeVie())
		nbAtributPareil++;

	if (pointDeVieTotal_ == creature.obtenirPointDeVieTotal())
		nbAtributPareil++;

	if(energie_ == creature.obtenirEnergie())
		nbAtributPareil++;

	if (energieTotal_ == creature.obtenirEnergieTotale())
		nbAtributPareil++;

	if (experience_ == creature.obtenirExperience())
		nbAtributPareil++;

	if (experienceNecessaire_ == creature.obtenirExperienceNecessaire())
		nbAtributPareil++;

	if (niveau_ == creature.obtenirNiveau())
		nbAtributPareil++;

	if (nbAtributPareil == 10)
		return true;
	else
		return false;

}


/**
* L'opérateur surchargé vérifie que le nom en paramètre est identique au nom du pouvoir en paramètre.
* \param [IN] nom Ce paramètre représente le nom du pouvoir qui est à comparer.
* \param [IN] pouvoir Ce paramètre représente le pouvoir dont on veut comparer le nom.
* \return La valeur de retour de la fonction est true si les noms sont identiques et false sinon.
*/

bool operator==(const string& nom, const Pouvoir& pouvoir)
{
	return(nom == pouvoir.obtenirNom());
}


/**
* L'opérateur surchargé affiche les informations de la créature passée en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] creature Ce paramètre représente la créature dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const Creature& creature)
{
	os << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en défense. " << endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Énergie." << endl
		<< "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << " d'XP." << endl
		<< "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau. " << endl
		<< "Pouvoirs : " << endl;

	if (creature.pouvoirs_.size() != 0)
	{
		for (int i = 0; i < creature.pouvoirs_.size(); i++)
		{
			os << "- " << i + 1 << " - " << *creature.pouvoirs_[i] << endl;
		}
	}

	else
	{
		os << creature.nom_ << " ne connait aucun pouvoir." << endl << endl;
	}

	return os;
}

#pragma region GET/SET

string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return pouvoirs_;
}

void Creature::modifierNom(const string& nom) {
	nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(const vector<Pouvoir*>& pouvoirs) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < pouvoirs_.size(); i++)
		delete pouvoirs_[i];
	pouvoirs_ = pouvoirs;
}

#pragma endregion


/**
* La fonction exécute les opérations nécessaires lors d'un combat pour déterminer le vainceur.
* \param [IN/OUT] creature Ce paramètre représente la créature adverse lors du combat. Cette créature se trouve
dans polyland et puisqu'elle est passée par référence, elle est modifiée directement dans polyland.
* \param [IN] pouvoir Ce paramètre sert à vérifier si la créature courante possède bien le pouvoir en paramètre.
*/

void Creature::attaquer(Pouvoir& pouvoir, Creature& creature)
{
	for (int i = 0; i < pouvoirs_.size(); i++) {
		if (*pouvoirs_[i] == pouvoir) {
			if (energie_ >= pouvoirs_[i]->obtenirEnergieNecessaire())
			{
				if (creature.obtenirPointDeVie() >= 0)
				{
					//Calcul du nombre de degat selon une formule 
					unsigned int degat = (pouvoirs_[i]->obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
					int tentative = rand() % 6;
					//l'attaque rate une fois sur 6
					if (tentative != 3)
					{
						cout << nom_ << " lance " << pouvoirs_[i]->obtenirNom() << " qui inflige " << degat << " dégats à " << creature.obtenirNom() << "." << endl;
						if (degat > creature.obtenirPointDeVie())
						{
							creature.modifierPointDeVie(0);
							int xp = experienceGagnee(creature);
							cout << nom_ << " a gagné " << xp << " XP." << endl;
						}
						else
							creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
						cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV." << endl;
						energie_ -= pouvoirs_[i]->obtenirEnergieNecessaire();
					}
					else
					{
						cout << "Attaque " << pouvoirs_[i]->obtenirNom() << " a échouée." << endl;
					}
				}
				else
					cout << "Vous avez déjà vaincu " << creature.obtenirNom() << "." << endl;
			}
		}
	}
	

}


/**
* La fonction calcule l'expérience gagnée par la créature du dresseur contre une créature de polyland passée en paramètre.
* \param [IN] creature Ce paramètre représente la créature adverse lors du combat. Selon les caractéristiques de la
créature, l'expérience gagnée variera.
* \return La valeur de retour de la fonction est l'expérience gagnée à la fin du combat.
*/

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
	{
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
		{
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
		{
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}


/**
* La fonction ajoute le pouvoir passé en paramètre à la créature si elle ne le possède pas.
* \param [IN] pouvoir Ce paramètre représente le pouvoir à apprendre par la créature.
* \return La valeur de retour de la fonction est la confirmation ou infirmation de l'ajout du pouvoir à la créature.
*/

bool Creature::apprendrePouvoir(const Pouvoir& pouvoir) {
	for (unsigned int i = 0; i < pouvoirs_.size(); i++)
	{
		if (*pouvoirs_[i] == pouvoir)
			return false;
	}

	pouvoirs_.push_back(new Pouvoir(pouvoir));
	return true;

}


/**
* La fonction retire le pouvoir passé en paramètre à la créature si elle le possède.
* \param [IN] pouvoir Ce paramètre représente le pouvoir à oublier par la créature. Ici, le pouvoir est un pointeur, 
					  car on veut retirer le pouvoir de la créature courante seulement et non de toutes les créatures.
* \return La valeur de retour de la fonction est la confirmation ou infirmation du retrait du pouvoir de la créature.
*/

bool Creature::oublierPouvoir(Pouvoir* pouvoir) {

	for (int i = 0; i < pouvoirs_.size(); i++) {
		if (*pouvoirs_[i] == *pouvoir) 
		{
			delete pouvoirs_[i];
			pouvoirs_[i] = pouvoirs_[(pouvoirs_.size() - 1)];
			pouvoirs_.pop_back();

			cout << "Le pouvoir " << pouvoir->obtenirNom() << " a bien été retiré." << endl;

			return true;
		}
	}

	cout << "Le pouvoir " << pouvoir->obtenirNom() << " n'a pas été retiré." << endl;
	return false;

}

