#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFIÉ
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree), genNbAlea_(RAND_MIN_DEFAUT, RAND_MAX_DEFAUT) //MODIFIÉ
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //MODIFIÉ
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

bool AttaqueMagiqueConfusion::estFini() const
{
	return ( duree_ <= 0 );
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
