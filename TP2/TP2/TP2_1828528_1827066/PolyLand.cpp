/**
*\ file : PolyLand.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 03/10/16
*\ Cr�� le : 28/09/16
*/

#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{}

PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{

	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}

}


/**
* La fonction ajoute un nouveau dresseur dans un vecteur de dresseurs s'il n'est pas d�j� pr�sent(Shallow Copy).
* \param [IN/OUT] dresseur Ce param�tre repr�sente un pointeur de l'objet dresseur qui doit �tre ajout� dans le vecteur.
* \return La valeur de retour de la fonction est true si le dresseur a bien �t� ajout�, sinon la valeur est false.
*/

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < dresseurs_.size(); i++) {
		if (*dresseurs_[i] == dresseur->obtenirNom())
		{
			cout << dresseur->obtenirNom() << " n'a pas �t� ajout�." << endl;
			return false;
		}
	}

	dresseurs_.push_back(dresseur);
	cout << dresseur->obtenirNom() << " a bien �t� ajout�!" << endl;
	return true;
}

/**
* La fonction ajoute une nouvelle cr�ature dans un vecteur de cr�atures si elle n'est pas d�j� pr�sente (Deep Copy).
* \param [IN/OUT] creature Ce param�tre repr�sente un pointeur vers l'objet cr�ature qui doit �tre ajout� dans le vecteur.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� ajout�e, sinon la valeur est false.
*/

bool PolyLand::ajouterCreature(const Creature* creature) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == creature->obtenirNom())
			return false;
	}
	creatures_.push_back(new Creature(*creature));
	cout << creature->obtenirNom() << " a bien �t� ajout�!" << endl;
	return true;
}


/**
* La fonction retire un dresseur du vecteur de dresseurs s'il y est pr�sent.
* \param [IN/OUT] nom Ce param�tre repr�sente le nom du dresseur dans le vecteur qui doit �tre retir�.
* \return La valeur de retour de la fonction est true si le dresseur a bien �t� retir�, sinon la valeur est false.
*/

bool PolyLand::retirerDresseur(const  string& nom) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < dresseurs_.size(); i++) {
		if (*dresseurs_[i] == nom) {
			dresseurs_[i] = dresseurs_[(dresseurs_.size() - 1)];
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}


/**
* La fonction retire une cr�ature du vecteur de cr�atures si elle y est pr�sente.
* \param [IN] nom Ce param�tre repr�sente le nom de la cr�ature dans le vecteur qui doit �tre retir�e.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� retir�e, sinon la valeur est false.
*/

bool PolyLand::retirerCreature(const  string& nom) // A MODIFIER... (si necessaire)
{
	{
		for (int i = 0; i < creatures_.size(); i++) {
			if (*creatures_[i] == nom) {
				delete creatures_[i];
				creatures_[i] = creatures_[(creatures_.size() - 1)];
				creatures_.pop_back();
				return true;
			}
		}
		return false;
	}
}


/**
* La fonction choisit un dresseur de fa�on al�atoire dans le vecteur de dresseurs.
* \return La fonction retourne un pointeur de type dresseur, qui correspond � une des cases du vecteur de dresseurs.
*/

Dresseur* PolyLand::choisirDresseurAleatoire() const{ // A MODIFIER... (si necessaire)
	if (dresseurs_.size() > 0)
	{
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
	{
		return nullptr;
	}
}


/**
* La fonction choisit une cr�ature de fa�on al�atoire dans le vecteur de cr�atures.
* \return La fonction retourne un pointeur de type cr�ature, qui correspond � une des cases du vecteur de cr�atures.
*/

Creature* PolyLand::choisirCreatureAleatoire() const // A MODIFIER... (si necessaire)
{
	if (creatures_.size() > 0) 
	{
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr; //
	}
}


/**
* La fonction confirme si la cr�ature pass�e en param�tre a bien �t� attrap�e par le dresseur pass� en param�tre �galement.
* \param [IN/OUT] dresseur Ce param�tre repr�sente un pointeur vers le dresseur qui tente d'attraper la cr�ature.
* \param [IN] creature Ce param�tre repr�sente un pointeur vers la cr�ature de polyland que le dresseur tente de capturer.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� attrap�e, sinon la valeur est false.
*/

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature* creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
	
}


/**
* La fonction retire une cr�ature du vecteur de cr�atures si elle y est pr�sente.
* \param [IN/OUT] nomCreature Ce param�tre repr�sente le nom de la cr�ature dans le vecteur qui doit �tre retir�e.
* \param [IN] dresseur Ce param�tre repr�sente le dresseur duquel on retire la cr�ature.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� retir�e, sinon la valeur est false.
*/

bool PolyLand::relacherCreature(Dresseur* dresseur, const  string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);

}


/**
* La fonction ajoute un nouveau dresseur � PolyLand (Shallow Copy).
* \param [IN/OUT] dresseur Ce param�tre repr�sente un pointeur de l'objet dresseur qui doit �tre ajout� dans le vecteur de dresseur de PolyLand.
* \return PolyLand avec l'ajout effectu�.
*/

PolyLand& PolyLand::operator+=(Dresseur* dresseur) {
	ajouterDresseur(dresseur);
	return *this;
}


/**
* La fonction retire un dresseur de PolyLand s'il y est pr�sent.
* \param [IN/OUT] dresseur Ce param�tre repr�sente le dresseur dans le vecteur qui doit �tre retir�.
* \return PolyLand avec le retrait effectu�.
*/

PolyLand& PolyLand::operator-=(const Dresseur* dresseur) {
	retirerDresseur(dresseur->obtenirNom());
	return *this;
}


/**
* La fonction ajoute une nouvelle cr�ature � PolyLand (Deep Copy).
* \param [IN] creature Ce param�tre repr�sente un pointeur vers l'objet cr�ature qui doit �tre ajout� dans le vecteur de dresseur de PolyLand.
* \return PolyLand avec l'ajout effectu�.
*/

PolyLand& PolyLand::operator+=(const Creature* creature) {
	ajouterCreature(creature);
	return *this;
}


/**
* La fonction retire une cr�ature de PolyLand si elle y est pr�sente.
* \param [IN] creature Ce param�tre repr�sente la cr�ature dans le vecteur qui doit �tre retir�e.
* \return PolyLand avec le retrait effectu�.
*/

PolyLand& PolyLand::operator-=(const Creature* creature) {
	retirerCreature(creature->obtenirNom());
	return *this;
}


/**
* La fonction permet d'afficher les informations sur PolyLand.
* \param [in] polyland Ce param�tre repr�sente le nom du PolyLand qu'on d�sire afficher.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \return os Ce return retourne l'affichage d�sir� sous la forme d'un os.
*/

ostream& operator<<(ostream& os, const PolyLand& polyland)
{
	for (int i = 0; i < polyland.dresseurs_.size(); i++)
	{
		os << *polyland.dresseurs_[i];
	}
	return os;
}
