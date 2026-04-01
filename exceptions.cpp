#include "exceptions.h"

const char* InvalidInput::what() const noexcept{
    return message.c_str();
}