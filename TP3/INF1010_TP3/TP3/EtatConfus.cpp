/**
*\ file : EtatConfus.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "EtatConfus.h"

EtatConfus::EtatConfus()
{
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const string& nom) :EtatCreature(nom)
{
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat_confus;
}

EtatConfus::~EtatConfus() {}


/**
* La fonction peutAttaquer pour cet �tat retourne que la cr�ature peut attaquer avec une certaine probabilit�.
* \return La valeur de retour est true si la valeur al�atoire est divisible par deux, false sinon.
*/

bool EtatConfus::peutAttaquer() const
{
	return rand() % 2 == 0;
}


/**
* La fonction appliquerEtat applique l'�tat d�termin� � la cr�ature pass�e en param�tre.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature dont l'�tat actuel est modifi�.
*/

void EtatConfus::appliquerEtat(Creature& creature)
{
	if (rand() % 3 == 0)
	{
		if (creature.getPointDeVie() * 0.95 >= 5)
		{
			creature.setPointDeVie(creature.getPointDeVie() * 0.95);
		}

		else
		{	
			if (creature.getPointDeVie() >= 5)
				creature.setPointDeVie(creature.getPointDeVie() - 5);
			else
				creature.setPointDeVie(0);
		}
	}

	duree_--;
}


/**
* La fonction estFini v�rifie si la dur�e est finie, selon des probabilit�s.
* \return La fonction retourne true si la valeur al�atoire est divisible par trois, false sinon.
*/

bool EtatConfus::estFini() const
{
	if (rand() % 3 == 0)
	{
		return true;
	}

	else
		return (duree_ <= 0);
}


/**
* L'op�rateur surcharg� affiche les informations de l'�tat pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] etatConfus Ce param�tre repr�sente l'�tat dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const EtatConfus& etatConfus)
{
	os << "�tat confus : " << etatConfus.getNom() << "durera " << etatConfus.duree_ << endl;

	return os;
}