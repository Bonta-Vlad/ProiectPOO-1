#include <exception>
#include <string>
class InvalidInput: public std::exception{
    std::string message;
    public:
    InvalidInput(const char* msg): message(msg){}
    const char* what() const noexcept{ return message.c_str();}
};