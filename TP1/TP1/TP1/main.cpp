﻿/**
*\ file : main.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include <iostream>
#include "Creature.h"
#include "Dresseur.h"
#include "Polyland.h" //Polyland sans L
#include "Pouvoir.h"
#include "ObjetMagique.h"
#include <time.h>
#include <clocale>  // pour setlocale
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "CREATION DES DRESSEURS" << endl;
	// Creer les dresseurs suivants (nom):
	Dresseur* Sasha = new Dresseur("Sasha");
	Dresseur* Pierre = new Dresseur("Pierre");
	Dresseur* Regis = new Dresseur("Regis");
	// A COMPLETER...

	cout << endl << "CREATION ET AFFICHAGE DES CREATURES" << endl;
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, energue, pouvoir):
	Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir pistoletAEau("Pistolet a eau", 6, 6);
	Pouvoir eclair("Eclair", 10, 5);
	Pouvoir lanceFeuille("Lance feuille", 5, 5);
	Creature Pokachu("Pokachu", 10, 2, 50, 25, eclair);
	Creature Salimouche("Salimouche", 12, 3, 45, 20, bouleDeFeu);
	Creature Carapouce("Carapouce", 10, 1, 55, 25, pistoletAEau);
	Creature Balbazar("Balbazar", 11, 2, 50, 22, lanceFeuille);



	// Afficher les informations sur Pokachu creature (en utilisant la methode d'affichage)
	// A COMPLETER...
	Pokachu.information();

	cout << endl << "Ajout des creatures et dresseurs de Polyland" << endl;

	PolyLand polyland;
	Dresseur Vous("Vous");
	polyland.addDresseur(Vous);
	polyland.addDresseur(*Sasha);
	polyland.addDresseur(*Pierre);
	polyland.addDresseur(*Regis);
	polyland.addCreature(Pokachu);
	polyland.addCreature(Salimouche);
	polyland.addCreature(Carapouce);
	polyland.addCreature(Balbazar);

	// add les dresseurs et les creatures à Polyland
	// A COMPLETER...


	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	cout << endl << "BIENVENUE A POLYLAND" << endl;

	Sasha->addCreature(Salimouche);// -> par .
	Pierre->addCreature(Balbazar);
	Regis->addCreature(Carapouce);

	cout << endl << "Choix de la premiere creature" << endl;

	Vous.addCreature(Pokachu);

	cout << "Vous etes chanceux voici un Pokachu rien que pour vous" << endl;


	//Duel entre vous et salimouche
	cout << endl << "TESTS DE COMBAT" << endl;

	cout << endl << "Un Salimouche surgit" << endl;

	cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << endl;

	Salimouche.attaquer(*(Vous.getCreatures())[0]);
	Vous.getCreatures()[0]->attaquer(Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.getPointDeVie() > 0)
	{
		((Vous.getCreatures())[0])->attaquer(Salimouche);
	}
	cout << "Vous avez battu un Salimouche, vous pouvez maintenant le capturer" << endl;

	//Vous avez déjà le droit a votre seconde creature
	if (polyland.attraperCreature(Vous, Salimouche)) // enlevé &
	{
		cout << "Felicitation vous avez attrapé un Salimouche !" << endl;
	}
	else
	{
		//ce cas ne devrait pas s'afficher
		cout << "Le salimouche s'est échappé" << endl;
	}

	cout << endl;
	cout << endl << "LA DECOUVERTE DE LA POTION MAGIQUE" << endl;
	cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachu" << endl;

	ObjetMagique potionMagique("Potion magique", 15);
	//Vous venez de trouver une potion magique
	Vous.setObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.getObjetMagique().affichage();
	Vous.useObjetMagique(Vous.getCreatures()[0]);

	//Choix d'une creature aleatoirement parmi celles possibles
	Creature* creatureAleatoire = polyland.choisirCreatureAleatoire();

	//Debut du duel avec la creature choisie aléatoirement
	cout << endl << "Un " << creatureAleatoire->getNom() << " se jette sur votre Pokachu" << endl;
	cout << "Un duel entre Pokachu et " << creatureAleatoire->getNom() << " est engagé" << endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (creatureAleatoire->getPointDeVie() > 0)
	{
		if (Vous.getCreatures()[0]->getPointDeVie() > 0)
		{
			//... ou que votre créature est morte
			(Vous.getCreatures()[0])->attaquer(*creatureAleatoire);
			if (creatureAleatoire->getPointDeVie() > 0)
				creatureAleatoire->attaquer(*Vous.getCreatures()[0]);
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (creatureAleatoire->getPointDeVie() == 0)
		cout << "Vous avez vaincu " << creatureAleatoire->getNom() << endl;
	else
	{
		//Sinon votre seconde créature se charge de finir le combat
		while (creatureAleatoire->getPointDeVie() > 0)
			(Vous.getCreatures()[1])->attaquer(*creatureAleatoire);
		cout << "Votre Pokachu a été battu mais heuresement votre Salimouche finit par vaincre " << creatureAleatoire->getNom() << endl;
	}
	cout << "Vous essayez d'attraper " << creatureAleatoire->getNom() << endl;
	//Vous ne pouvez pas attraper la nouvel créature, vous avez déjà ateint la limite
	if (polyland.attraperCreature(Vous, *creatureAleatoire)) //enlevé &
	{
		//ce cas ne devrait pas s'afficher
		cout << "Felicitation vous avez attrapé un " << creatureAleatoire->getNom() << " !" << endl;
	}
	else
	{
		//Elle s'échappe donc
		cout << creatureAleatoire->getNom() << " s'est échappé" << endl;
	}

	cout << endl << "AFFICHAGE DE VOS INFORMATIONS" << endl;
	Dresseur* dresseurAleatoire = polyland.choisirDresseurAleatoire();
	polyland.addDresseur(Vous); // enlevé &
	polyland.infoDresseur("Vous");

	cout << "Pokachu et salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Salimouche" << endl;
	polyland.infoDresseur("Sasha");
	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(Vous, "Salimouche")) //enlevé &
	{
		cout << "Vous avez decidé de relacher Salimouche !" << endl;
	}
	else
	{
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... Salimouche n'a pas pu être relaché" << endl;
	}

	//On soigne votre Pokachu
	Vous.getCreatures()[0]->setPointDeVie(Vous.getCreatures()[0]->getPointDeVieTotal());
	Vous.getCreatures()[0]->setEnergie(Vous.getCreatures()[0]->getEnergieTotal());

	cout << endl << "UN DRESSEUR SOUHAITE VOUS DEFIEZ" << endl;
	dresseurAleatoire->affichage();
	//Vous vous faites toujours attaquer dans Polyland, ça serait presque une terre hostile...
	cout << dresseurAleatoire->getNom() << " surgit avec son " << dresseurAleatoire->getCreatures()[0]->getNom() << endl;

	cout << "Un duel entre Pokachu et " << dresseurAleatoire->getCreatures()[0]->getNom() << " est engagé" << endl;
	//Mais vous allez gagner ;)
	while (dresseurAleatoire->getCreatures()[0]->getPointDeVie() > 0)
	{
		if (Vous.getCreatures()[0]->getPointDeVie() > 0)
		{
			(Vous.getCreatures()[0])->attaquer(*dresseurAleatoire->getCreatures()[0]);
			if (dresseurAleatoire->getCreatures()[0]->getPointDeVie() > 0)
				dresseurAleatoire->getCreatures()[0]->attaquer(*Vous.getCreatures()[0]);
		}
		else
		{
			//Vous avez trouvé un puit de potion pour régénrer votre Pokachu
			cout << "Votre Pokachu est mal en point, vous utilisez une potion sur lui " << endl;
			Vous.useObjetMagique(Vous.getCreatures()[0]);
		}
	}

	//Vous n'êtes pas sympa vous avez fait fuir un dresseur de Polyland...
	cout << endl << "Suite à sa défaite " << dresseurAleatoire->getNom() << " s'enfuit de Polyland" << endl;
	if (polyland.removeDresseur(dresseurAleatoire->getNom()))
	{
		cout << dresseurAleatoire->getNom() << " s'est bien enfuit de Polyland..." << endl;
	}
	else
	{
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... " << dresseurAleatoire->getNom() << "n'a pas pu s'enfuir" << endl;
	}


	cout << endl << "INFO DRESSEUR APRES TOUTES CES PERIPETIES" << endl;
	polyland.infoDresseur("Vous");
	//On ne devrait plus avoir d'information sur le dresseur aleatoire qui s'est enfui
	polyland.infoDresseur(dresseurAleatoire->getNom());
	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/

	// Liberer les ressources s'il le faut
	// A COMPLETER...
	
	delete Sasha;
	delete Pierre;
	delete Regis;

	//system("pause");
	return 0;
}
