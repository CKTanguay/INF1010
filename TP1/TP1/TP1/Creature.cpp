/**
*\ file : Creature.cpp
*\ Auteurs : Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (187066)
*\ Date de dernière modification : 26/09/16
*\ Créé le : 14/09/16
*/

#include "Creature.h"
#include <clocale>  // pour setlocale


Creature::Creature()
{
	nom_ = "";
	attaque_ = 0;
	defense_ = 0;
	pointDeVie_ = 0;
	pointDeVieTotal_ = 0;
	energie_ = 0;
	energieTotal_ = 0;
	experience_ = 0;
	experienceNecessaire_ = 0;
	niveau_ = 0;
}

Creature::Creature(const string nom, int attaque, int defense, int pointDeVie, int energie, Pouvoir pouvoir)
{
	nom_ = nom;
	attaque_ = attaque;
	defense_ = defense;
	pointDeVie_ = pointDeVie;
	pointDeVieTotal_ = pointDeVie;
	energie_ = energie;
	energieTotal_ = energie;
	experience_ = 0;
	experienceNecessaire_ = EXPERIENCE_NECESSAIRE;
	niveau_ = NIVEAU_INITIAL;
	pouvoir_ = pouvoir;

}

Creature::~Creature() {}

#pragma region GET/SET

string Creature::getNom() const
{
	return nom_;
}
int Creature::getAttaque() const
{
	return attaque_;
}
int Creature::getDefense() const
{
	return defense_;
}
int Creature::getPointDeVie() const
{
	return pointDeVie_;
}
int Creature::getPointDeVieTotal() const
{
	return pointDeVieTotal_;
}
int Creature::getEnergie() const
{
	return energie_;
}
int Creature::getEnergieTotal() const
{
	return energieTotal_;
}
int Creature::getExperience() const
{
	return experience_;
}
int Creature::getExperienceNecessaire() const
{
	return experienceNecessaire_;
}
int Creature::getNiveau() const
{
	return niveau_;
}
Pouvoir Creature::getPouvoir() const
{
	return pouvoir_;
}

void Creature::setNom(string nom)
{
	nom_ = nom;
}
void Creature::setAttaque(int attaque)
{
	attaque_ = attaque;
}
void Creature::setDefense(int defense)
{
	defense_ = defense;
}
void Creature::setPointDeVie(int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}
void Creature::setPointDeVieTotal(int pointDeVieTotal)
{
	pointDeVieTotal_ = pointDeVieTotal;
}
void Creature::setEnergie(int energie)
{
	energie_ = energie;
}
void Creature::setEnergieTotal(int energieTotal)
{
	energieTotal_ = energieTotal;
}
void Creature::setExperience(int experience)
{
	experience_ = experience;
}
void Creature::setExperienceNecessaire(int experienceNecessaire)
{
	experienceNecessaire_ = experienceNecessaire;
}
void Creature::setNiveau(int niveau)
{
	niveau_ = niveau;
}
void Creature::setPouvoir(Pouvoir pouvoir)
{
	pouvoir_ = pouvoir;
}

#pragma endregion

/**
* La fonction exécute les opérations nécessaires lors d'un combat pour déterminer le vainceur.
* \param [IN/OUT] creature Ce paramètre représente la créature adverse lors du combat. Cette créature se trouve 
dans polyland et puisqu'elle est passée par référence, elle est modifiée directement dans polyland et non dans la 
classe créature.
*/

void Creature::attaquer(Creature & creature)
{
	setlocale(LC_ALL, "");

	if (pouvoir_.getEnergieNeccessaire() <= energie_ && creature.getPointDeVie() > 0)
	{
		//L'attaque est possible si votre créature a assez d'energie
		//Et que la creature adverse a encore des points de vie
		//Si la creature adverse n'a plus de vie, afficher un message en conséquent

		//Calcul du nombre de degat selon une formule
		unsigned int degat = (pouvoir_.getDegat())* (attaque_ / 2 - creature.defense_);
		//On choisit un nombre aléatoire entre 1 et 6
		int tentative = (rand() % 6) + 1;
		//l'attaque rate une fois sur 6
		if (tentative != 3)
		{
			//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
			//le nombre de dégat infligé, et la créature qui est attaquée
			cout << nom_ << " lance " << pouvoir_.getNom() << " qui inflige " << degat << " dégat à " << creature.getNom() << endl;

			//Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
			//les modifications adéquates											
			
			creature.setPointDeVie(creature.getPointDeVie() - degat);

			int exp = experienceGagner(creature);
			experience_ += exp;
			
			if (creature.getPointDeVie() <= 0)
			{
				cout << nom_ << " a gagné " << exp << " XP" << endl;
			}

			if (creature.getPointDeVie()<0)
			{
				creature.setPointDeVie(0);
			}

			//Afficher le nombre de point de vie restant de la créature attaquée
			//Faites attention aux requis d'une attaque

			cout << creature.getNom() << " a encore " << creature.getPointDeVie() << " PV." << endl;
		}

		else
		{
			// L'attaque a raté
			cout << "Attaque " << pouvoir_.getNom() << " a échoué." << endl;
		}
	}
}


/**
* La fonction calcule l'expérience gagnée par la créature du dresseur contre une créature de polyland passée en paramètre.
* \param [IN/OUT] creature Ce paramètre représente la créature adverse lors du combat. Selon les caractéristiques de la 
créature, l'expérience gagnée variera.
* \return La valeur de retour de la fonction est l'expérience gagnée à la fin du combat.
*/

int Creature::experienceGagner(const Creature& creature)
{
	if (creature.getPointDeVie() <= 0)
	{
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) *
			(creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_))
		{
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else
		{
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}


/**
* La fonction permet tout simplement l'affichage des informations sur la créature.
*/

void Creature::information()
{
	setlocale(LC_ALL, "");

	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ << " en defense," << endl;
	cout << "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et " << energie_ << "/" << energieTotal_ << " Energie" << endl;
	cout << "Il est au niveau " << niveau_ << " avec " << experience_ << " d'XP" << endl;
	cout << "Il lui manque " << experienceNecessaire_ << " jusqu'au prochain niveau" << endl;
	pouvoir_.affichage();
}