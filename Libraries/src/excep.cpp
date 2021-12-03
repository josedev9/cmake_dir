#include "excep.h"
OpeningVideoError::OpeningVideoError()  noexcept =default;
OpeningVideoError::~OpeningVideoError() noexcept =default;
const char* OpeningVideoError::what() const noexcept {return "Unexpected file used for reading/writing fatal error";}