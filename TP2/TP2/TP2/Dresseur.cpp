/**
*\ file : Dresseur.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 03/10/16
*\ Cr�� le : 28/09/16
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
* L'op�rateur permet de comparer si deux dresseurs ont les m�mes cr�atures.
* \param [IN] dresseur2 Ce param�tre repr�sente le dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont les m�mes cr�atures et false dans le cas contraire.
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
* L'op�rateur permet de comparer si deux dresseurs ont le m�me nom.
* \param [IN] nomDresseur Ce param�tre repr�sente le nom du dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont le m�me nom et false dans le cas contraire.
*/

bool Dresseur::operator==(const string& nomDresseur) const {
	return (nom_ == nomDresseur);
}


/**
* L'op�rateur permet de comparer si deux dresseurs ont le m�me nom.
* \param [IN] nom Ce param�tre repr�sente le nom du premier dresseur avec lequel on veut faire la comparaison.
* \param [IN] dresseur Ce param�tre repr�sente le deuxi�me dresseur avec lequel on veut faire la comparaison.
* \return La valeur de retour de la fonction est true si les dresseurs ont le m�me nom et false dans le cas contraire.
*/

bool operator==(const string& nom, const Dresseur& dresseur)
{
	return(nom == dresseur.obtenirNom());
}


/**
* L'op�rateur surcharg� affiche les informations du dresseur pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] dresseurAfficher Ce param�tre repr�sente le dresseur dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const Dresseur& DresseurAfficher)
{
	os << DresseurAfficher.obtenirNom() << " poss�de " << DresseurAfficher.obtenirNombreCreatures()
		<< " cr�ature(s) et appartient � l'�quipe " << DresseurAfficher.obtenirEquipe() << "." << endl;
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
* La fonction permet d'utiliser un objet magique selon l'�nergie et les points de vie de la cr�ature.
* \param [IN] creature Ce param�tre repr�sente la cr�ature sur laquelle on utilise l'objet magique.
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
* La fonction ajoute une nouvelle cr�ature dans le vecteur si elle n'y est pas d�j�.
* \param [IN] creature Ce param�tre repr�sente la cr�ature qui est ajout�e au vecteur.
* \return La valeur de retour de la fonction est true si l'ajout a bien �t� fait et false dans le cas contraire.
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
* La fonction retire une cr�ature du vecteur de cr�atures si elle s'y trouve.
* \param [IN] nom Ce param�tre repr�sente le nom de la cr�ature qui est retir�e du vecteur. Elle est de type const, donc
m�me si elle est pass�e en r�f�rence, elle ne peut pas �tre modifi�e.
* \return La valeur de retour de la fonction est true si le retrait a bien �t� fait et false dans le cas contraire.
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
