/**
*\ file : EtatEmpoisonne.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
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
* La fonction appliquerEtat applique l'état déterminé à la créature passée en paramètre.
* \param [IN/OUT] creature Ce paramètre représente la créature dont l'état actuel est modifié.
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
* La fonction estFini vérifie si la durée est finie.
* \return La fonction retourne true si la duree est plus petite ou égale à 0, false sinon.
*/

bool EtatEmpoisonne::estFini() const
{
	return(duree_ <= 0);
}
 

/**
* L'opérateur surchargé affiche les informations de l'état passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] etatEmpoisonne Ce paramètre représente l'état dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream& operator<<(ostream& os, const EtatEmpoisonne& etatEmpoisonne)
{
	os << "état empoisonné : " << etatEmpoisonne.getNom() << " durera " << etatEmpoisonne.duree_ << endl;

	return os;
	
}