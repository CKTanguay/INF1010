/**
*\ file : main.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
*\ Date de dernière modification : 24/10/16
*\ Créé le : 05/10/16
*/

#include <iostream>
#include <time.h>
#include <typeinfo>

#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "Professeur.h"
#include "CreatureMagique.h"
#include "PotionMagique.h"
#include "PouvoirPoison.h"
#include "PouvoirHallucinogene.h"
#include "PouvoirSoporifique.h "
#include "GreenBull.h"
#include "Elixir.h"
#include "EtatCreature.h"
#include "EtatConfus.h"
#include "EtatEmpoisonne.h"
#include "EtatEndormi.h"

void appliquerEtatSelonType(Creature& creature) {
	EtatCreature* etat = creature.getEtat();
	EtatEmpoisonne* etatPoison;
	EtatEndormi* etatEndormi;
	EtatConfus* etatConfus;
	switch (etat->getType())
	{
	case TypeEtat_normal:
		etat->appliquerEtat(creature);
		break;
	case TypeEtat_empoisonne:
		etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
		etatPoison->appliquerEtat(creature);
		break;
	case TypeEtat_endormi:
		etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
		etatEndormi->appliquerEtat(creature);
		break;
	case TypeEtat_confus:
		etatConfus = static_cast<EtatConfus*>(creature.getEtat());
		etatConfus->appliquerEtat(creature);
		break;
	default:
		break;
	}
}

//TODO à compléter appelle la méthode appropriée selon le type
//dit si la créature peut attaquer, il faut appeler la bonne
// méthode de étatCréature ou d'une de ses classes filles
bool peutAttaquerSelonType(Creature& creature) {
	bool peutAttaquer = false;
	EtatCreature* etat = creature.getEtat();
	EtatEmpoisonne* etatPoison;
	EtatEndormi* etatEndormi;
	EtatConfus* etatConfus;
	switch (etat->getType())
	{
	case TypeEtat_normal:
		peutAttaquer = etat->peutAttaquer();
		break;
	case TypeEtat_empoisonne:
		etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
		peutAttaquer = etatPoison->peutAttaquer();
		break;
	case TypeEtat_endormi:
		etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
		peutAttaquer = etatEndormi->peutAttaquer();
		break;
	case TypeEtat_confus:
		etatConfus = static_cast<EtatConfus*>(creature.getEtat());
		peutAttaquer = etatConfus->peutAttaquer();
		break;
	default:
		break;
	}
	return peutAttaquer;
}

//TODO à compléter (s'inpirer des fonctions au-dessus)
bool estFiniSelonType(Creature& creature) {
	bool estFini = false;
	EtatCreature* etat = creature.getEtat();
	EtatEmpoisonne* etatPoison;
	EtatEndormi* etatEndormi;
	EtatConfus* etatConfus;
	switch (etat->getType())
	{
	case TypeEtat_normal:
		estFini = etat->estFini();
		break;
	case TypeEtat_empoisonne:
		etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
		estFini = etatPoison->estFini();
		break;
	case TypeEtat_endormi:
		etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
		estFini = etatEndormi->estFini();
		break;
	case TypeEtat_confus:
		etatConfus = static_cast<EtatConfus*>(creature.getEtat());
		estFini = etatConfus->estFini();
		break;
	default:
		break;
	}
	return estFini;
}

//TODO étudier le fonctionnement et s'en inspirer pour l'implémentation des 
//operator << dans les classes filles /!\ il est probable qu'il faille
//que l'opérateur<< ne travaille pas, il faudra sûrement adapter la méthode 
//ci-dessous
// kjbegggggggggggggggggggggggggggggggglgjbejbejbejbe
void afficherEtatSelonType(Creature& creature) {
	EtatCreature* etat = creature.getEtat();
	EtatEmpoisonne* etatPoison;
	EtatEndormi* etatEndormi;
	EtatConfus* etatConfus;
	cout << creature.getNom() << " est dans l'état: ";
	switch (etat->getType())
	{
	case TypeEtat_normal:
		cout << *etat << endl;
		break;
	case TypeEtat_empoisonne:
		etatPoison = static_cast<EtatEmpoisonne*>(creature.getEtat());
		cout << *etatPoison << endl;
		break;
	case TypeEtat_endormi:
		etatEndormi = static_cast<EtatEndormi*>(creature.getEtat());
		cout << *etatEndormi << endl;
		break;
	case TypeEtat_confus:
		etatConfus = static_cast<EtatConfus*>(creature.getEtat());
		cout << *etatConfus << endl;
		break;
	default:
		break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "BIENVENU DANS LE MONDE MERVEILLEUX DE POLYLAND" << endl;
	//TODO créez un Professeur nommé Chen ("Chen", "Laboratoire Poly")
	Professeur Chen("Chen", "Laboratoire Poly");
	
	OutilScientifique scanner("scanner", "étudier une créature");
	cout << scanner << endl;
	Chen.setOutilScientifique(scanner);
	Dresseur mauvaisGars("Jessie", "Team Rocket");

	//TODO créez les créatures suivantes
	Creature miaouss("Miaouss", 10, 2, 50, 22);
	Creature pokachu("Pokachu", 10, 2, 100, 25);
	Creature Salimouche("Salimouche", 12, 3, 45, 20);
	Creature rondodu("Rondodu", 10, 2, 50, 25);
	CreatureMagique mewtwo("Mewtwo", 10, 3, 50, 25, 5); //jai enleve le 20 dattaque originel car on veut 10.
	
	cout << "TEST : affichage de la créature magique" << endl;
	cout << mewtwo << endl;
	cout << "FIN TEST : affichage de la créature magique" << endl;

	//TODO Créez les pouvoirs suivants
	Pouvoir eclair("Eclair", 10, 5);
	PouvoirPoison morsureVenin("Morsure Venin", 10, 5, 3);
	PouvoirHallucinogene ondeFolie("Onde Folie", 4, 5, 4);
	PouvoirSoporifique berceuse("Berceuse", 2, 5, 2);
	PouvoirHallucinogene telekinesie("Telekinesie", 15, 5, 4);
	
	cout << "TEST AFFICHAGE Pouvoir" << endl;
	cout << eclair << endl;
	cout << morsureVenin << endl;
	cout << ondeFolie << endl;
	cout << berceuse << endl;
	cout << telekinesie << endl;
	cout << "FIN : TEST AFFICHAGE Pouvoir" << endl;

	pokachu.apprendrePouvoir(&eclair);
	miaouss.apprendrePouvoir(&morsureVenin);
	miaouss.apprendrePouvoir(&ondeFolie);
	rondodu.apprendrePouvoir(&berceuse);
	mewtwo.apprendrePouvoir(&telekinesie);

	mauvaisGars.ajouterCreature(&miaouss);
	Chen.ajouterCreature(&Salimouche);

	cout << "TEST PolyLand " << endl;
	PolyLand polyland;
	polyland += &miaouss;
	polyland += &pokachu;
	polyland += &rondodu;
	polyland += &mewtwo;
	polyland += &Chen; 
	polyland += &mauvaisGars;
	cout << polyland << endl;
	cout << "FIN TEST PolyLand " << endl;

	Dresseur Vous("Etudiant", "Team INF1010");
	Vous.ajouterCreature(&pokachu);
	cout << "LA TEAM MISSILE VOUS ATTAQUE" << endl;
	while (miaouss.getPointDeVie() > 0 && pokachu.getPointDeVie() > 0)
	{      
		miaouss.attaquer(morsureVenin, pokachu);
		morsureVenin.appliquerEffetOffensif(pokachu);
		//Pauvre pokachu, l'attaque l'a possibelment empoisonne!
		appliquerEtatSelonType(pokachu);
		if (peutAttaquerSelonType(pokachu))
			pokachu.attaquer( eclair, miaouss);

		if (estFiniSelonType(pokachu))
			pokachu.setEtat(new EtatCreature("normal")); //attention aux fuites mémoires

		cout << "affichage de l'etat de Pokachu" << endl;
		cout << "Pokachu est dans l'état: " << *(pokachu.getEtat()) << endl;
		cout << "affichage de l'etat de Pokachu (autre méthode)" << endl;
		afficherEtatSelonType(pokachu);
	}

	if (pokachu.getPointDeVie() > 0) {
		cout << "Felicitation vous avez gagne" << endl;
	}
	else {
		cout << "Hum Pokachu est mal en point" << endl;
	}
	//Test potion magique
	PotionMagique potion("Potion", 10);
	unsigned int ancienPointDeVie = pokachu.getPointDeVie();
	cout << "Vous utilisez une potion magique" << endl;
	cout << potion << endl;
	potion.utiliserSur(pokachu);
	if (pokachu.getPointDeVie() == ancienPointDeVie + 10)
		cout << "Potion: OK" << endl;

	//Test GreenBull
	GreenBull boissonTonique("greenBull", 10);
	unsigned int ancienneEnergie = pokachu.getEnergie();
	cout << "Vous utilisez une boisson énergisante" << endl;
	cout << boissonTonique << endl;
	boissonTonique.utiliserSur(pokachu);
	if (pokachu.getEnergie() == ancienneEnergie + 10)
		cout << "GreenBull: OK" << endl;

	//Test elixir
	pokachu.setEnergie(pokachu.getEnergie() - 10);
	ancienneEnergie = pokachu.getEnergie();
	ancienPointDeVie = pokachu.getPointDeVie();
	Elixir elixir("elixir", 10);
	elixir.utiliserSur(pokachu);
	if (pokachu.getEnergie() == ancienneEnergie + 10 &&
		pokachu.getPointDeVie() == ancienPointDeVie + 20) {
		cout << "Elixir: OK" << endl;
	}
	//Le professeur soigne votre créature
	Chen.soigner(pokachu);
	if (pokachu.getPointDeVie() == pokachu.getPointDeVieTotal() &&
		pokachu.getEnergie() == pokachu.getEnergieTotale()) {
		cout << "Soigner: OK" << endl;
	}

	cout << "C'est incroyable, une créature magique vous attaque" << endl;
	while (mewtwo.getPointDeVie() > 0 && pokachu.getPointDeVie() > 0)
	{
		//l'attaqe devrait augmenter les points de vie de la créature
		unsigned int pointDeVie = mewtwo.getPointDeVie();
		mewtwo.attaquer(telekinesie, pokachu);
		telekinesie.appliquerEffetOffensif(pokachu);
		//Pauvre pokachu, l'attaque l'a possibelment empoisonne!
		appliquerEtatSelonType(pokachu);
		//Les points de vie de la créature doivent augmenter 
		//quand elle attaque

		if (mewtwo.getPointDeVie() >= pointDeVie) {
			cout << "Creature magique OK" << endl;
		}
		telekinesie.appliquerEffetOffensif(pokachu);

		//TODO : appliquer l'état selon le type
		//Indice: regardez plus haut dans le code
		if (peutAttaquerSelonType(pokachu))
			pokachu.attaquer(eclair, mewtwo);

		if (estFiniSelonType(pokachu))
			pokachu.setEtat(new EtatCreature(" normal"));

		//TODO : afficher l'etat en prenant en compte le type
		//Indice: regardez plus haut dans le code
		//et répondre à la question relative à l'affichage
	}
	Chen.soigner(pokachu);
	cout << "Votre Pokachu surprend un rondodu, terrifié celui-ci lui chante une berceuse" << endl;
	rondodu.attaquer(berceuse, pokachu);
	berceuse.appliquerEffetOffensif(pokachu);
	//rondodu devrait dormir pour deux tours
	for (unsigned int i = 0; i < 4; ++i) {
		appliquerEtatSelonType(pokachu);
	}
	if (estFiniSelonType(pokachu)) {
		cout << "Pokachu s'est réveillé! : Berceuse OK" << endl;
	}
	else {
		cout << "Bizarre pokachu aurait dû se réveiller..." << endl;
	}
	//Attention aux double free et fuites mémoires
	Professeur Phelina(Chen);
	Professeur Orme(Chen);
	Orme = Phelina;
	//vérification de la copie
	cout << "TEST Professeur : affichage de l'information des professeurs" << endl;
	cout << Chen << endl;
	cout << Orme << endl;
	cout << Phelina << endl;
	cout << "FIN TEST" << endl;

	return 0;
}