/**
*\ file : main.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 03/10/16
*\ Créé le : 28/09/16
*/

#include <iostream>
#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include <time.h>
#include <clocale>  // pour setlocale

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "CRÉATION DES DRESSEURS" << endl;
	// Creer DYNAMIQUEMENT les dresseurs suivants (nom):
	Dresseur* Sasha = new Dresseur("Sacha", "Team de feu");
	Dresseur* Pierre=new Dresseur("Pierre", "Équipe de Poly");
	Dresseur* Regis = new Dresseur("Régis", "Équipe de Poly");
	// A COMPLETER...


	cout << endl << "CRÉATION ET AFFICHAGE DES CRÉATURES" << endl << endl;
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, mana):
	Creature Pokachu ("Pokachu", 10, 2, 50, 25);
	Creature Salimouche ("Salimouche", 12, 3, 45, 20);
	Creature Carapouce("Carapouce", 10, 1, 55, 25);
	Creature Balbazar("Balbazar", 11, 2, 50, 22);
	// A COMPLETER...

	// Creer la Creature Touflamme en utilisant l'opérateur = et en utilisant la creature existante Salimouche.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...
	Creature Touflamme = Salimouche; // veriffier si sa delete pas lautre
	Touflamme.modifierNom("Touflamme");
	Touflamme.modifierAttaque(15);



	// Creer la Creature Pokachoum en utilisant le constructeur de copie et en utilisant la creature existante Pokachu.
	// Le nom de Pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...
	Creature Pokachoum(Pokachu);
	Pokachoum.modifierNom("Pokachoum");
	Pokachoum.modifierDefense(7);

	// Afficher les informations sur Pokachu, Touflamme et PokachOum 
	// A COMPLETER...
	cout << Pokachu;
	cout << Touflamme;
	cout << Pokachoum;

	// Creer les pouvoirs suivants
	Pouvoir bouleDeFeu ("Boule de feu", 5, 5);
	Pouvoir pistoletAEau ("Pistolet à eau", 6, 6);
	Pouvoir eclair ("Éclair", 10, 5);
	// A COMPLETER...


	// Creer le pouvoir lanceFeuille en utilisant le contructeur par copie et en utilisant le pouvoir bouleDeFeu.
	// Le nom du pouvoir lanceFeuille doit ensuite etre modifie pour "Lance Feuille".
	// A COMPLETER...
	Pouvoir lanceFeuille(bouleDeFeu);
	lanceFeuille.modifierNom("Lance Feuille");


	// Creer le pouvoir tonerre en utilisant l'operateur = et en utilisant le pouvoir eclair.
	// Le nom du pouvoir tonerre doit ensuite etre modifie pour "Tonerre" et son nombre de degat doit etre diminue a 3.
	// A COMPLETER...
	Pouvoir tonerre = eclair;
	tonerre.modifierNom("Tonerre");
	tonerre.modifierNombreDeDegat(3);


	// Faites afficher les informations des pouvoirs bouleDeFeu, lanceFeuille et tonnerre.
	// A COMPLETER...
	cout << bouleDeFeu;
	cout << lanceFeuille;
	cout << tonerre;


	// Ajouter le pouvoir a la creature correspondante
	Salimouche.apprendrePouvoir(bouleDeFeu);
	Carapouce.apprendrePouvoir(pistoletAEau);
	Balbazar.apprendrePouvoir(lanceFeuille);
	Pokachu.apprendrePouvoir(eclair);
	Pokachu.apprendrePouvoir(tonerre);
	Touflamme.apprendrePouvoir(tonerre);
	Pokachoum.apprendrePouvoir(eclair);
	// A COMPLETER...

	cout << endl << "AJOUT DE CRÉATURES ET DE DRESSEURS À POLYLAND" << endl << endl;

	PolyLand polyland;
	
	// Ajouter les dresseurs et les creatures. Attention, vous devez utiliser l'operateur += pour ajouter un dresseur.
	// A COMPLETER...

	polyland += &Salimouche;
	polyland += &Carapouce;
	polyland += &Balbazar;
	polyland += &Pokachu;
	polyland += &Touflamme;
	polyland += &Pokachoum;
	polyland += Regis;	
	polyland += Pierre;
	polyland += Sasha;

	//Ce dresseur est deja present, il ne devrais pas s'ajouter.
	// A COMPLETER...
	polyland += Pierre;
	cout << endl << "TEST D'AFFICHAGE" << endl << endl;
	// Tests d'affichage
	cout << polyland << endl;
	cout << *(polyland.choisirCreatureAleatoire()) << endl;
	cout << *(polyland.choisirDresseurAleatoire()) << endl;

	cout << endl << "COMPÉTITION" << endl;
	// Debut de la competition
	cout << endl << "Bienvenue à Polyland!" << endl << endl;
	Dresseur Vous("Hey", "Team INF1010");

	cout << bouleDeFeu << endl;
	cout << lanceFeuille << endl;
	cout << tonerre << endl;
	

	// Cette commande ne devrait pas fonctionner
	Carapouce.oublierPouvoir(&eclair);   

	// Assignez une creature au dresseur.
	// A COMPLETER...
	Sasha->ajouterCreature(&Salimouche);
	Pierre->ajouterCreature(&Balbazar);
	Regis->ajouterCreature(&Carapouce);
	// Assignez à vous-meme Pokachu
	// A COMPLETER...
	Vous.ajouterCreature(&Pokachu);
	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	//Duel entre vous et salimouche
	cout << endl << "TESTS DE COMBAT" << endl;

	cout << endl << "Un Salimouche surgit" << endl;

	cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << endl;

	Salimouche.attaquer(bouleDeFeu, *(Vous.obtenirUneCreature("Pokachu")));
	Vous.obtenirUneCreature("Pokachu")->attaquer(eclair, Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.obtenirPointDeVie() > 0)
	{
		((Vous.obtenirUneCreature("Pokachu")))->attaquer(eclair, Salimouche);
	}
	cout << endl << "Vous avez battu un Salimouche, vous pouvez maintenant le capturer." << endl;

	if (polyland.attraperCreature(&Vous, &Salimouche))
	{
		cout << "Félicitation vous avez attrapé un Salimouche!" << endl;
	}
	else
	{
		cout << "Le Salimouche s'est échappé" << endl;
	}


	cout << endl;
	cout << "Vous trouvez une potion magique, vous décidez de l'utiliser sur Pokachu." << endl;

	ObjetMagique potionMagique("Potion magique", 15);
	cout << potionMagique << endl;
	//Vous venez de trouver une potion magique
	Vous.modifierObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.utiliserObjetMagique(Vous.obtenirUneCreature("Pokachu"));

	//Choix d'une creature aleatoirement parmi celles possibles
	Creature* creatureAleatoire = polyland.choisirCreatureAleatoire();
	//Debut du duel avec la creature choisie aléatoirement
	cout << endl << "Un " << creatureAleatoire->obtenirNom() << " se jette sur votre Pokachu." << endl;
	cout << "Un duel entre Pokachu et " << creatureAleatoire->obtenirNom() << " est engagé!" << endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (creatureAleatoire->obtenirPointDeVie() > 0)
	{
		if (Vous.obtenirUneCreature("Pokachu")->obtenirPointDeVie() > 0)
		{
			//... ou que votre créature est morte
			(Vous.obtenirUneCreature("Pokachu"))->attaquer(eclair, *creatureAleatoire);
			if (creatureAleatoire->obtenirPointDeVie() > 0)
				creatureAleatoire->attaquer(*(creatureAleatoire->obtenirPouvoirs()[0]), *(Vous.obtenirUneCreature("Pokachu")));
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (creatureAleatoire->obtenirPointDeVie() == 0)
		cout << "Vous avez vaincu " << creatureAleatoire->obtenirNom() << "." << endl;
	else
	{
		//Sinon votre seconde créature se charge de finir le combat
		while (creatureAleatoire->obtenirPointDeVie() > 0)
			(Vous.obtenirUneCreature("Salimouche"))->attaquer(bouleDeFeu, *creatureAleatoire);
		cout << "Votre Pokachu a été battu, mais heuresement votre Salimouche finit par vaincre " << creatureAleatoire->obtenirNom() << "." << endl;
	}





	cout << endl << "Pokachu et Salimouche n'arrêtent pas de se chamailler, vous décidez d'abandonner Salimouche." << endl;

	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(&Vous, "Salimouche"))
	{
		cout << "Vous avez decidé de relâcher Salimouche!" << endl;
	}
	else
	{
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... Salimouche n'a pas pu être relaché." << endl;
	}

	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/


	cout << endl << "INFO DRESSEUR APRÈS TOUTES CES PÉRIPÉTIES" << endl;
	// Afficher les informations de Polyland
	// A COMPLETER...

	cout << polyland << endl;

	cout << endl << "DERNIER TESTS" << endl;
	// Cette commande ne devrait pas fonctionner
	Carapouce.oublierPouvoir(&eclair);

	// Suite a un combat intense, Carapouce perd son pouvoir pistoletAEau. Retirez ce pouvoir.
	// A COMPLETER...
	Carapouce.oublierPouvoir(&pistoletAEau);

	// test des opérateurs == de la classe Dresseur
	Dresseur test1("test", "testeur");
	Dresseur test2("test", "testeur");
	test1.ajouterCreature(&Pokachu);
	test1.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Pokachu);

	cout << "________________________________________________" << endl;
	cout << "TEST OPERATEURS" << endl << endl;
	cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Réponse attendue : 1" << endl;
	cout << "dresseur == nom : \t" << (test1 == test2.obtenirNom()) << " --- Réponse attendue : 1" << endl;
	cout << "nom == dresseur : \t" << (test1.obtenirNom() == test2) << " --- Réponse attendue : 1" << endl;

	test1.ajouterCreature(&Carapouce);
	cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Réponse attendue : 0" << endl;

	test1.modifierNom("testNouveau");
	cout << "dresseur == nom : \t" << (test1 == test2.obtenirNom()) << " --- Réponse attendue : 0" << endl;
	cout << "nom == dresseur : \t" << (test1.obtenirNom() == test2) << " --- Réponse attendue : 0" << endl;


	// Liberer les ressources s'il le faut
	// A COMPLETER...
	delete Sasha;
	delete Pierre;
	delete Regis;

	system("pause");
	return 0;
}