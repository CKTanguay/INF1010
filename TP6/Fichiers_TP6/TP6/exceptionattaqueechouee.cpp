#include "ExceptionAttaqueEchouee.h"

ExceptionAttaqueEchouee::ExceptionAttaqueEchouee(const std::string & what_arg = "") : std::runtime_error(what_arg) {}
