/**
*\ file : EtatEmpoisonne.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
*/

#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne()
{
	type_ = TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const string& nom) :EtatCreature(nom)
{
	type_ =TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat_empoisonne;
}

EtatEmpoisonne::~EtatEmpoisonne(){}


/**
* La fonction appliquerEtat applique l'�tat d�termin� � la cr�ature pass�e en param�tre.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature dont l'�tat actuel est modifi�.
*/

void EtatEmpoisonne::appliquerEtat(Creature& creature)
{
	if (creature.getPointDeVie() >= 5)
		creature.setPointDeVie(creature.getPointDeVie() - 5); 
	else
		creature.setPointDeVie(0);

	if (duree_ != 0)
		duree_--;
}


/**
* La fonction estFini v�rifie si la dur�e est finie.
* \return La fonction retourne true si la duree est plus petite ou �gale � 0, false sinon.
*/

bool EtatEmpoisonne::estFini() const
{
	return(duree_ <= 0);
}
 

/**
* L'op�rateur surcharg� affiche les informations de l'�tat pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] etatEmpoisonne Ce param�tre repr�sente l'�tat dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream& operator<<(ostream& os, const EtatEmpoisonne& etatEmpoisonne)
{
	os << "�tat empoisonn� : " << etatEmpoisonne.getNom() << " durera " << etatEmpoisonne.duree_ << endl;

	return os;
	
}