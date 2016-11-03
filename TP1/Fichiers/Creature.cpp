#include "Creature.h"

void Creature::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
        //L'attaque est possible si votre créature a assez d'energie
        //Et que la creature adverse a encore des points de vie

            //Calcul du nombre de degat selon une formule
            unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
            //On choisit un nombre aléatoire entre 1 et 6
            int tentative = rand() % 6;
            //l'attaque rate une fois sur 6
            if (tentative != 3) {
                //Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
                //le nombre de dégat infligé, et la créature qui est attaquée

                //Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
                //les modifications adéquates

                //Afficher le nombre de point de vie restant de la créature attaquée
                //Faites attention aux requis d'une attaque
            }
            else {
                //La créature adverse est déjà vaincue
                std::cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
            }


}

int Creature::experienceGagner(const Creature& creature)
{
    if (creature.obtenirPointDeVie() <= 0) {
        //Calcul de l'experience selon une formule mystérieuse
        int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) *
         (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
        if (experience > (experienceNecessaire_ - experience_)) {
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
        else {
            experience_ += experience;
        }
        return experience;
    }
    return 0;
}
