#include "ExceptionCreatureMorte.h"

ExceptionCreatureMorte::ExceptionCreatureMorte(const std::string & what_arg) : std::runtime_error(what_arg) {
    compteur_++;
}

int ExceptionCreatureMorte::obtenirValeurCompteur()
{ return compteur_;}

int ExceptionCreatureMorte::compteur_=0;
