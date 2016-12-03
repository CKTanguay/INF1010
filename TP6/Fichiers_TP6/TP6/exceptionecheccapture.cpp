#include "ExceptionEchecCapture.h"

ExceptionEchecCapture::ExceptionEchecCapture(const std::string & what_arg = "") : std::runtime_error(what_arg) {}

