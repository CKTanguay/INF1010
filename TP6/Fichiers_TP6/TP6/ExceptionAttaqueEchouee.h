/*
Fichier: ExceptionAttaqueEchouee.h
Auteur(s):Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
Date de creation: 15 Novembre 2016
Description: Exception si la créature hero na plus assez d'energie pour attaquer
Date de dernière modification 4 Décembre 2016
*/
#ifndef EXCEPTIONATTAQUEECHOUEE_H
#define EXCEPTIONATTAQUEECHOUEE_H

#include <stdexcept>

class ExceptionAttaqueEchouee : public std::runtime_error
{
public:
    ExceptionAttaqueEchouee(const std::string & what_arg = ""):std::runtime_error(what_arg) {}
};

#endif // EXCEPTIONATTAQUEECHOUEE_H
