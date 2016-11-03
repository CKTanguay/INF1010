/**
*\ file : PolyLand.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
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
* La fonction ajoute un nouveau dresseur dans un vecteur de dresseurs s'il n'est pas déjà présent(Shallow Copy).
* \param [IN/OUT] dresseur Ce paramètre représente un pointeur de l'objet dresseur qui doit être ajouté dans le vecteur.
* \return La valeur de retour de la fonction est true si le dresseur a bien été ajouté, sinon la valeur est false.
*/

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < dresseurs_.size(); i++) {
		if (*dresseurs_[i] == dresseur->obtenirNom())
		{
			cout << dresseur->obtenirNom() << " n'a pas été ajouté." << endl;
			return false;
		}
	}

	dresseurs_.push_back(dresseur);
	cout << dresseur->obtenirNom() << " a bien été ajouté!" << endl;
	return true;
}

/**
* La fonction ajoute une nouvelle créature dans un vecteur de créatures si elle n'est pas déjà présente (Deep Copy).
* \param [IN/OUT] creature Ce paramètre représente un pointeur vers l'objet créature qui doit être ajouté dans le vecteur.
* \return La valeur de retour de la fonction est true si la créature a bien été ajoutée, sinon la valeur est false.
*/

bool PolyLand::ajouterCreature(const Creature* creature) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == creature->obtenirNom())
			return false;
	}
	creatures_.push_back(new Creature(*creature));
	cout << creature->obtenirNom() << " a bien été ajouté!" << endl;
	return true;
}


/**
* La fonction retire un dresseur du vecteur de dresseurs s'il y est présent.
* \param [IN/OUT] nom Ce paramètre représente le nom du dresseur dans le vecteur qui doit être retiré.
* \return La valeur de retour de la fonction est true si le dresseur a bien été retiré, sinon la valeur est false.
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
* La fonction retire une créature du vecteur de créatures si elle y est présente.
* \param [IN] nom Ce paramètre représente le nom de la créature dans le vecteur qui doit être retirée.
* \return La valeur de retour de la fonction est true si la créature a bien été retirée, sinon la valeur est false.
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
* La fonction choisit un dresseur de façon aléatoire dans le vecteur de dresseurs.
* \return La fonction retourne un pointeur de type dresseur, qui correspond à une des cases du vecteur de dresseurs.
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
* La fonction choisit une créature de façon aléatoire dans le vecteur de créatures.
* \return La fonction retourne un pointeur de type créature, qui correspond à une des cases du vecteur de créatures.
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
* La fonction confirme si la créature passée en paramètre a bien été attrapée par le dresseur passé en paramètre également.
* \param [IN/OUT] dresseur Ce paramètre représente un pointeur vers le dresseur qui tente d'attraper la créature.
* \param [IN] creature Ce paramètre représente un pointeur vers la créature de polyland que le dresseur tente de capturer.
* \return La valeur de retour de la fonction est true si la créature a bien été attrapée, sinon la valeur est false.
*/

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature* creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
	
}


/**
* La fonction retire une créature du vecteur de créatures si elle y est présente.
* \param [IN/OUT] nomCreature Ce paramètre représente le nom de la créature dans le vecteur qui doit être retirée.
* \param [IN] dresseur Ce paramètre représente le dresseur duquel on retire la créature.
* \return La valeur de retour de la fonction est true si la créature a bien été retirée, sinon la valeur est false.
*/

bool PolyLand::relacherCreature(Dresseur* dresseur, const  string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);

}


/**
* La fonction ajoute un nouveau dresseur à PolyLand (Shallow Copy).
* \param [IN/OUT] dresseur Ce paramètre représente un pointeur de l'objet dresseur qui doit être ajouté dans le vecteur de dresseur de PolyLand.
* \return PolyLand avec l'ajout effectué.
*/

PolyLand& PolyLand::operator+=(Dresseur* dresseur) {
	ajouterDresseur(dresseur);
	return *this;
}


/**
* La fonction retire un dresseur de PolyLand s'il y est présent.
* \param [IN/OUT] dresseur Ce paramètre représente le dresseur dans le vecteur qui doit être retiré.
* \return PolyLand avec le retrait effectué.
*/

PolyLand& PolyLand::operator-=(const Dresseur* dresseur) {
	retirerDresseur(dresseur->obtenirNom());
	return *this;
}


/**
* La fonction ajoute une nouvelle créature à PolyLand (Deep Copy).
* \param [IN] creature Ce paramètre représente un pointeur vers l'objet créature qui doit être ajouté dans le vecteur de dresseur de PolyLand.
* \return PolyLand avec l'ajout effectué.
*/

PolyLand& PolyLand::operator+=(const Creature* creature) {
	ajouterCreature(creature);
	return *this;
}


/**
* La fonction retire une créature de PolyLand si elle y est présente.
* \param [IN] creature Ce paramètre représente la créature dans le vecteur qui doit être retirée.
* \return PolyLand avec le retrait effectué.
*/

PolyLand& PolyLand::operator-=(const Creature* creature) {
	retirerCreature(creature->obtenirNom());
	return *this;
}


/**
* La fonction permet d'afficher les informations sur PolyLand.
* \param [in] polyland Ce paramètre représente le nom du PolyLand qu'on désire afficher.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \return os Ce return retourne l'affichage désiré sous la forme d'un os.
*/

ostream& operator<<(ostream& os, const PolyLand& polyland)
{
	for (int i = 0; i < polyland.dresseurs_.size(); i++)
	{
		os << *polyland.dresseurs_[i];
	}
	return os;
}
