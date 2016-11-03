/**
*\ file : Dresseur.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""), equipe_(""){};

Dresseur::Dresseur(const string& nom, const string& equipe): nom_(nom), equipe_(equipe){}

Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
}


/**
* L'opérateur permet de comparer si deux dresseurs ont les mêmes créatures.
* \param [IN] dresseur2 Ce paramètre représente le dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont les mêmes créatures et false dans le cas contraire.
*/

bool Dresseur::operator==(const Dresseur& dresseur2) const
{
	int nbCreaturePareilles = 0;

	if (creatures_.size() == dresseur2.creatures_.size())
	{
		for (int i = 0; i < creatures_.size();i++)
		{
			for (int j = 0; j < creatures_.size();j++) 
			{
				if (*creatures_[i] == *dresseur2.creatures_[j]) 
				{
					nbCreaturePareilles++;
					break;
				}
			}
		}
		return(nbCreaturePareilles == creatures_.size());
	}

	return false;
}


/**
* L'opérateur permet de comparer si deux dresseurs ont le même nom.
* \param [IN] nomDresseur Ce paramètre représente le nom du dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont le même nom et false dans le cas contraire.
*/

bool Dresseur::operator==(const string& nomDresseur) const {
	return (nom_ == nomDresseur);
}


/**
* L'opérateur permet de comparer si deux dresseurs ont le même nom.
* \param [IN] nom Ce paramètre représente le nom du premier dresseur avec lequel on veut faire la comparaison.
* \param [IN] dresseur Ce paramètre représente le deuxième dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont le même nom et false dans le cas contraire.
*/

bool operator==(const string& nom, const Dresseur& dresseur)
{
	return(nom == dresseur.obtenirNom());
}


/**
* L'opérateur surchargé affiche les informations du dresseur passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] dresseurAfficher Ce paramètre représente le dresseur dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const Dresseur& DresseurAfficher)
{
	os << DresseurAfficher.obtenirNom() << " possède " << DresseurAfficher.obtenirNombreCreatures()
		<< " créature(s) et appartient à l'équipe " << DresseurAfficher.obtenirEquipe() << "." << endl;
	return os;
}

#pragma region GET/SET

string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

Creature* Dresseur::obtenirUneCreature(const string& nomCreature) const // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == nomCreature)
			return creatures_[i];
	}
}

void Dresseur::modifierCreature(const vector<Creature*>& creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const string equipe)
{
	equipe_ = equipe;
}

#pragma endregion


/**
* La fonction permet d'utiliser un objet magique selon l'énergie et les points de vie de la créature.
* \param [IN] creature Ce paramètre représente la créature sur laquelle on utilise l'objet magique.
*/

void Dresseur::utiliserObjetMagique(Creature* creature)
{
	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}

	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}

	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}

	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}


/**
* La fonction ajoute une nouvelle créature dans le vecteur si elle n'y est pas déjà.
* \param [IN] creature Ce paramètre représente la créature qui est ajoutée au vecteur.
* \return La valeur de retour de la fonction est true si l'ajout a bien été fait et false dans le cas contraire.
*/

bool Dresseur::ajouterCreature(const Creature* creature) 
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i]==creature->obtenirNom())
			return false;
	}

	creatures_.push_back(new Creature(*creature));
	return true;
}


/**
* La fonction retire une créature du vecteur de créatures si elle s'y trouve.
* \param [IN] nom Ce paramètre représente le nom de la créature qui est retirée du vecteur. Elle est de type const, donc
même si elle est passée en référence, elle ne peut pas être modifiée.
* \return La valeur de retour de la fonction est true si le retrait a bien été fait et false dans le cas contraire.
*/

bool Dresseur::enleverCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == nom){
			delete creatures_[i];
			creatures_[i] = creatures_[(creatures_.size()-1)];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}
