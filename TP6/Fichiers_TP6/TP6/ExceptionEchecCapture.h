#ifndef EXCEPTIONEHECCAPTURE_H
#define EXCEPTIONEHECCAPTURE_H

#include <stdexcept>

class ExceptionEchecCapture : public std::runtime_error
{
public:

    ExceptionEchecCapture(const std::string & what_arg = ""):runtime_error(what_arg){}
};

#endif
