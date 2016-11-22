/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"
#include "Foncteur.h"


Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

auto Dresseur::obtenirCreatures() const
{
	return creatures_;
}

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const //� MODIFIFIER !!
{
	auto it =find_if(creatures_.begin(), creatures_.end(), FoncteurCreatureDeMemeNom(nom));
	//if (it != creatures_.end()) {
		return *it;
	//}
	//return nullptr;
}

void Dresseur::modifierCreature(std::list<Creature*> creatures) //A Compl�ter
{
	creatures_=creatures;
}

bool Dresseur::ajouterCreature(Creature* creature) 
{
	FoncteurEgalCreatures comparaison(creature);
	auto position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
	if (position_creature != creatures_.end())
		return false;

	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom) 
{
	FoncteurCreatureDeMemeNom foncteurComparaison(nom);
	auto position = find_if(creatures_.begin(), creatures_.end(), foncteurComparaison);
	if (position == creatures_.end())
		return false;

	creatures_.erase(position);

	return true;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}
/**
* La fonction compare deux dresseur et retourn un bool true s'ils sont pareil
* \param [IN] dresseur Ce param�tre repr�sente le dresseur au quelle on compare. Il est de type const, donc
m�me s'il est pass�e en r�f�rence, il ne peut pas �tre modifi�.
* \return La valeur de retour de la fonction est true dresseur1==dresseur2 et false dans le cas contraire.
*/
bool Dresseur::operator==(const Dresseur& dresseur) const //A compl�ter

{
	if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
		return true;
	else if (creatures_.size() != dresseur.creatures_.size())
		return false;

	for (auto it1 = dresseur.creatures_.begin(); it1 != dresseur.creatures_.end(); it1++) {
		auto it2 = find_if(creatures_.begin(), creatures_.end(), FoncteurCreatureDeMemeNom((*it1)->obtenirNom()));
		if (it2 == creatures_.end())
			return false;
	}

	return true;
}
bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
	return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() 
		<< " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}
