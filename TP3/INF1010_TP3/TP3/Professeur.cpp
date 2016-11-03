/**
*\ file : Professeur.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include "Professeur.h"

Professeur::Professeur()
{
	outilScientifique_ = nullptr;
}

Professeur::Professeur(const string& nomProfesseur, const string& equipe) : Dresseur(nomProfesseur, equipe) 
{
	outilScientifique_ = nullptr;
}

Professeur::~Professeur()
{
	//delete prof
}

Professeur::Professeur(const Professeur& professeur) : Dresseur(professeur) //constructeur par copie
{
	outilScientifique_ = new OutilScientifique(*professeur.getOutilScientifique());
}

#pragma region GET/SET

OutilScientifique* Professeur::getOutilScientifique() const
{
	return outilScientifique_;
}

void Professeur::setOutilScientifique(OutilScientifique& outilScientifique) //peut etre ajouter un const dans le futur
{
	outilScientifique_ = new OutilScientifique(outilScientifique.getNom(), outilScientifique.getDescription());
}

#pragma endregion


/**
 La fonction soigner rétablit l'énergie et les points de vie d'une créature à leurs valeurs maximales.
* \param [IN/OUT] creature Ce paramètre représente la créature à soigner.
*/

void Professeur::soigner(Creature& creature)
{
	creature.setPointDeVie(creature.getPointDeVieTotal());
	creature.setEnergie(creature.getEnergieTotale());
}


/**
* L'opérateur surchargé copie les attributs d'un outil passé en paramètre vers un outil déjà existant.
* \param [IN] outilScientifique Ce paramètre représente l'outil scientifique à partir duquel on copie les attributs.
*/

void Professeur::operator=(OutilScientifique& outilScientifique2)
{
	outilScientifique_->setNom(outilScientifique2.getNom());
	outilScientifique_->setDescription(outilScientifique2.getDescription());
}


/**
* L'opérateur surchargé affiche les informations de l'objet PotionMagique passé en paramètre.
* \param [OUT] os Ce paramètre représente le flux de données à afficher à l'écran.
* \param [IN] potionMagique Ce paramètre représente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de données.
*/

ostream & operator<<(ostream& os, const Professeur& professeur)
{
	os << static_cast<const Dresseur&>(professeur) << "il utilise un outil : " << professeur.getOutilScientifique()->getNom()
		<< " qui permet de " << professeur.getOutilScientifique()->getDescription() << endl;

	return os;
}