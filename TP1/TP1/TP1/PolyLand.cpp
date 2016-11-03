/**
*\ file : PolyLand.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include "Polyland.h"
#include <clocale>  // pour setlocale


PolyLand::PolyLand()
{
	nbCreature_ = 0;
	nbDresseur_ = 0;
	creature_ = new	Creature*[1000];
	for (int i = 0; i < 1000; i++)
	{
		creature_[i] = nullptr;
	}
	dresseur_ = new	Dresseur*[100];
	for (int i = 0; i < 100; i++)
	{
		dresseur_[i] = nullptr;
	}
}

PolyLand::~PolyLand()
{
	for (int i = 0; i < 1000; i++)
		delete creature_[i];
	delete[] creature_;
	for (int i = 0; i < 100; i++)
		delete dresseur_[i];
	delete[] dresseur_;
}


/**
* La fonction ajoute un nouveau dresseur dans un tableau de dresseurs s'il n'est pas déjà présent.
* \param [IN] dresseur Ce paramètre représente l'objet dresseur qui doit être ajouté dans le tableau.
* \return La valeur de retour de la fonction est true si le dresseur a bien été ajouté, sinon la valeur est false.
*/

bool PolyLand::addDresseur(Dresseur dresseur)
{
	for (int i = 0; i < nbDresseur_; i++)
	{
		if (dresseur.getNom() == (dresseur_[i])->getNom())
			return false;
	}
	dresseur_[nbDresseur_] = &dresseur;
	nbDresseur_++;
	return true;
}


/**
* La fonction retire un dresseur du tableau de dresseurs s'il y est présent.
* \param [IN/OUT] nomDresseur Ce paramètre représente le nom du dresseur dans le tableau qui doit être retiré.
* \return La valeur de retour de la fonction est true si le dresseur a bien été retiré, sinon la valeur est false.
*/

bool PolyLand::removeDresseur(const string& nomDresseur)
{
	int positionDresseur = 0;
	bool dresseurPresent = false;

	for (int i = 0; i < nbDresseur_; i++)
	{
		if (nomDresseur == (dresseur_[i])->getNom())
		{
			positionDresseur = i;
			i - nbDresseur_; 
			dresseurPresent = true;
		}
	}

	for (positionDresseur; positionDresseur < nbDresseur_; positionDresseur++)
		dresseur_[positionDresseur] = dresseur_[++positionDresseur];

	nbDresseur_--;
	dresseur_[nbDresseur_] = nullptr;
	delete dresseur_[nbDresseur_];
	return dresseurPresent;
}


/**
* La fonction ajoute une nouvelle créature dans un tableau de créature si elle n'est pas déjà présente.
* \param [IN/OUT] creature Ce paramètre représente l'objet creature qui doit être ajouté dans le tableau.
* \return La valeur de retour de la fonction est true si la créature a bien été ajoutée, sinon la valeur est false.
*/

bool PolyLand::addCreature(Creature& creature)
{
	for (int i = 0; i < nbCreature_; i++)
	{
		if (creature.getNom() == (creature_[i])->getNom())
			return false;
	}
	creature_[nbCreature_] = &creature;
	nbCreature_++;
	return true;
}


/**
* La fonction retire une créature du tableau de réatures si elle y est présente.
* \param [IN/OUT] nomCreature Ce paramètre représente le nom de la créature dans le tableau qui doit être retirée.
* \return La valeur de retour de la fonction est true si la créature a bien été retirée, sinon la valeur est false.
*/

bool PolyLand::removeCreature(const string& nomCreature)
{
	int positionCreature = 0;
	bool creaturePresente = false;
	for (int i = 0; i < nbCreature_; i++)
	{
		if (nomCreature == (creature_[i])->getNom())
		{
			positionCreature = i;
			i = nbCreature_; //arreter la boucle car inutil apres
			creaturePresente = true;
			//dresseur_[i] = nullptr;
			//delete dresseur_[i];
		}
	}
	for (positionCreature; positionCreature < nbCreature_; positionCreature++)
	{
		creature_[positionCreature] = creature_[++positionCreature];
	}
	nbCreature_--;
	creature_[nbCreature_] = nullptr;
	delete creature_[nbCreature_];
	return creaturePresente;
}


/**
* La fonction choisit un dresseur de façon aléatoire dans le tableau de dresseurs.
* \return La fonction retourne un pointeur de type dresseur, qui correspond à une des cases du tableau de dresseurs.
*/

Dresseur* PolyLand::choisirDresseurAleatoire()
{
	srand(time(NULL));
	int dresseurChoisi = rand() % nbDresseur_;
	return (dresseur_[dresseurChoisi]);
}


/**
* La fonction choisit une créature de façon aléatoire dans le tableau de créatures.
* \return La fonction retourne un pointeur de type créature, qui correspond à une des cases du tableau de créatures.
*/

Creature* PolyLand::choisirCreatureAleatoire()
{
	srand(time(NULL));
	int creatureChoisi = rand() % nbCreature_;
	return (creature_[creatureChoisi]);
}


/**
* La fonction confirme si la créature passée en paramètre a bien été attrapée par le dresseur passé en paraètre également.
* \param [IN/OUT] dresseur Ce paramètre représente l'adresse du dresseur qui tente d'attraper la créature.
* \param [IN] creature Ce paramètre représente la créature de polyland que le dresseur tente de capturer.
* \return La valeur de retour de la fonction est true si la créature a bien été attrapée, sinon la valeur est false.
*/

bool PolyLand::attraperCreature(Dresseur& dresseur, Creature creature)
{
	return dresseur.addCreature(creature);
}


/**
* La fonction confirme si la créature passée en paramètre a bien été relâchée par le dresseur passé en paraètre également.
* \param [IN/OUT] dresseur Ce paramètre représente l'adresse du dresseur qui tente de relaâcher la créature.
* \param [IN] nomCreature Ce paramètre représente le nom de la créature de polyland que le dresseur tente de relâcher.
* \return La valeur de retour de la fonction est true si la créature a bien été relâchée, sinon la valeur est false.
*/

bool PolyLand::relacherCreature(Dresseur& dresseur, string nomCreature)
{
	return dresseur.removeCreature(nomCreature);
}


/**
* La fonction permet tout simplement l'affichage des informations sur la créature.
*/

void PolyLand::infoDresseur(string nomDresseur)
{
	setlocale(LC_ALL, "");

	for (int i = 0; i < nbDresseur_; i++)
	{
		if (nomDresseur == dresseur_[i]->getNom())
		{
			for (int j = 0; j < dresseur_[i]->getNombreCreatures(); j++)
			{
				cout << "- " << ++j << " - ";
				dresseur_[i]->getCreatures()[j]->information();
			}
		}
	}
}