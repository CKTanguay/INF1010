#ifndef EXCEPTIONATTAQUEECHOUEE_H
#define EXCEPTIONATTAQUEECHOUEE_H

#include <stdexcept>

class ExceptionAttaqueEchouee : public std::runtime_error
{
public:
    ExceptionAttaqueEchouee(const std::string & what_arg = ""):std::runtime_error(what_arg) {}
};

#endif // EXCEPTIONATTAQUEECHOUEE_H
