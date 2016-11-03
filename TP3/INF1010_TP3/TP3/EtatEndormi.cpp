/**
*\ file : EtatEndormi.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "EtatEndormi.h"

EtatEndormi::EtatEndormi()
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const string& nom) : EtatCreature(nom)
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::~EtatEndormi() {}


/**
* La fonction peutAttaquer pour cet �tat retourne que la cr�ature ne peut pas attaquer.
* \return La valeur de retour par d�faut est false.
*/

bool EtatEndormi::peutAttaquer() const
{
	return false;
}


/**
* La fonction appliquerEtat applique l'�tat d�termin� � la cr�ature pass�e en param�tre.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature dont l'�tat actuel est modifi�.
*/

void EtatEndormi::appliquerEtat(Creature& creature)
{
	if (duree_ > 0)
		duree_--;
}


/**
* La fonction estFini v�rifie si la dur�e est finie.
* \return La fonction retourne true si la duree est plus petite ou �gale � 0, false sinon.
*/

bool EtatEndormi::estFini() const
{
	if (duree_ <= 0)
		return true;

	return false;
}


/**
* L'op�rateur surcharg� affiche les informations de l'�tat pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] etatEndormi Ce param�tre repr�sente l'�tat dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const EtatEndormi& etatEndormi)
{
	os << "�tat endormi : " << etatEndormi.getNom() << " durera " << etatEndormi.duree_ << endl;

	return os;
}
