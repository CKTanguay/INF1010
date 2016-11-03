/**
*\ file : PolyLand.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de derni�re modification : 26/09/16
*\ Cr�� le : 14/09/16
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
* La fonction ajoute un nouveau dresseur dans un tableau de dresseurs s'il n'est pas d�j� pr�sent.
* \param [IN] dresseur Ce param�tre repr�sente l'objet dresseur qui doit �tre ajout� dans le tableau.
* \return La valeur de retour de la fonction est true si le dresseur a bien �t� ajout�, sinon la valeur est false.
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
* La fonction retire un dresseur du tableau de dresseurs s'il y est pr�sent.
* \param [IN/OUT] nomDresseur Ce param�tre repr�sente le nom du dresseur dans le tableau qui doit �tre retir�.
* \return La valeur de retour de la fonction est true si le dresseur a bien �t� retir�, sinon la valeur est false.
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
* La fonction ajoute une nouvelle cr�ature dans un tableau de cr�ature si elle n'est pas d�j� pr�sente.
* \param [IN/OUT] creature Ce param�tre repr�sente l'objet creature qui doit �tre ajout� dans le tableau.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� ajout�e, sinon la valeur est false.
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
* La fonction retire une cr�ature du tableau de r�atures si elle y est pr�sente.
* \param [IN/OUT] nomCreature Ce param�tre repr�sente le nom de la cr�ature dans le tableau qui doit �tre retir�e.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� retir�e, sinon la valeur est false.
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
* La fonction choisit un dresseur de fa�on al�atoire dans le tableau de dresseurs.
* \return La fonction retourne un pointeur de type dresseur, qui correspond � une des cases du tableau de dresseurs.
*/

Dresseur* PolyLand::choisirDresseurAleatoire()
{
	srand(time(NULL));
	int dresseurChoisi = rand() % nbDresseur_;
	return (dresseur_[dresseurChoisi]);
}


/**
* La fonction choisit une cr�ature de fa�on al�atoire dans le tableau de cr�atures.
* \return La fonction retourne un pointeur de type cr�ature, qui correspond � une des cases du tableau de cr�atures.
*/

Creature* PolyLand::choisirCreatureAleatoire()
{
	srand(time(NULL));
	int creatureChoisi = rand() % nbCreature_;
	return (creature_[creatureChoisi]);
}


/**
* La fonction confirme si la cr�ature pass�e en param�tre a bien �t� attrap�e par le dresseur pass� en para�tre �galement.
* \param [IN/OUT] dresseur Ce param�tre repr�sente l'adresse du dresseur qui tente d'attraper la cr�ature.
* \param [IN] creature Ce param�tre repr�sente la cr�ature de polyland que le dresseur tente de capturer.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� attrap�e, sinon la valeur est false.
*/

bool PolyLand::attraperCreature(Dresseur& dresseur, Creature creature)
{
	return dresseur.addCreature(creature);
}


/**
* La fonction confirme si la cr�ature pass�e en param�tre a bien �t� rel�ch�e par le dresseur pass� en para�tre �galement.
* \param [IN/OUT] dresseur Ce param�tre repr�sente l'adresse du dresseur qui tente de rela�cher la cr�ature.
* \param [IN] nomCreature Ce param�tre repr�sente le nom de la cr�ature de polyland que le dresseur tente de rel�cher.
* \return La valeur de retour de la fonction est true si la cr�ature a bien �t� rel�ch�e, sinon la valeur est false.
*/

bool PolyLand::relacherCreature(Dresseur& dresseur, string nomCreature)
{
	return dresseur.removeCreature(nomCreature);
}


/**
* La fonction permet tout simplement l'affichage des informations sur la cr�ature.
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