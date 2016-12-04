/*
Fichier: ExceptionAttaqueEchouee.h
Auteur(s):Maxime Brousseau (1828528) et Christophe Kedzierski-Tanguay (1827066)
Date de creation: 15 Novembre 2016
Description: Exception si la créature adverse ne peut pas être capturée.
Date de dernière modification 4 Décembre 2016
*/
#ifndef EXCEPTIONEHECCAPTURE_H
#define EXCEPTIONEHECCAPTURE_H

#include <stdexcept>

class ExceptionEchecCapture : public std::runtime_error
{
public:

    ExceptionEchecCapture(const std::string & what_arg = ""):runtime_error(what_arg){}
};

#endif
