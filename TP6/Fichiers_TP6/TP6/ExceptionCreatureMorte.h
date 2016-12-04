/*
Fichier: ExceptionCreatureMorte.h
Auteur(s):Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
Date de creation: 15 Novembre 2016
Description: Exception si la créature adverse est morte
Date de dernière modification 4 Décembre 2016
*/
#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H

#include <stdexcept>
#include <string>

class ExceptionCreatureMorte : public std::runtime_error
{
public:
    ExceptionCreatureMorte(const std::string & what_arg = "");

    static int obtenirValeurCompteur();

private:
    static int compteur_;
};

#endif
