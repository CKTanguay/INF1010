/**
*\ file : AttaqueMagiqueConfusion.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 21/11/16
*\ Cr�� le : 02/11/16
*/
#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFI�
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFI�
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}
/**
* La fonction appliquerAttaque applique l'effet d'une attaque sur une cr�ature pass�e en param�tre.
* \param [OUT] creature Ce param�tre repr�sente la cr�ature sur laquelle on applique l'attaque magique poison.
*/
void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //MODIFI�
{
	if (duree_ > 0 && creature.obtenirPointDeVie() >= 5) 
	{
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		if (genNbAlea_() == 0) 
		{
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		duree_--;
	}
}
/**
* La fonction estFini retourne true ou false selon la dur�e.
* \return La fonction retourne true si la dur�e est de 0, false sinon.
*/
bool AttaqueMagiqueConfusion::estFini() const
{
	return ( duree_ <= 0 );
}
/**
* La fonction obtenirTypeAttaque permet de retourner le type de l'attaque.
* \return La valeur de retour de la fonction est une cha�ne de caract�res repr�sentant le type de l'attaque, soit AttaqueMagiquePoison.
*/
std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
