/**
*\ file : Professeur.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de derni�re modification : 24/10/16
*\ Cr�� le : 05/10/16
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
 La fonction soigner r�tablit l'�nergie et les points de vie d'une cr�ature � leurs valeurs maximales.
* \param [IN/OUT] creature Ce param�tre repr�sente la cr�ature � soigner.
*/

void Professeur::soigner(Creature& creature)
{
	creature.setPointDeVie(creature.getPointDeVieTotal());
	creature.setEnergie(creature.getEnergieTotale());
}


/**
* L'op�rateur surcharg� copie les attributs d'un outil pass� en param�tre vers un outil d�j� existant.
* \param [IN] outilScientifique Ce param�tre repr�sente l'outil scientifique � partir duquel on copie les attributs.
*/

void Professeur::operator=(OutilScientifique& outilScientifique2)
{
	outilScientifique_->setNom(outilScientifique2.getNom());
	outilScientifique_->setDescription(outilScientifique2.getDescription());
}


/**
* L'op�rateur surcharg� affiche les informations de l'objet PotionMagique pass� en param�tre.
* \param [OUT] os Ce param�tre repr�sente le flux de donn�es � afficher � l'�cran.
* \param [IN] potionMagique Ce param�tre repr�sente l'objet dont on veut afficher les informations.
* \return La valeur de retour de la fonction est un flux de donn�es.
*/

ostream & operator<<(ostream& os, const Professeur& professeur)
{
	os << static_cast<const Dresseur&>(professeur) << "il utilise un outil : " << professeur.getOutilScientifique()->getNom()
		<< " qui permet de " << professeur.getOutilScientifique()->getDescription() << endl;

	return os;
}