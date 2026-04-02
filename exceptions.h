#include <exception>
#include <string>
class InvalidInput: public std::exception{
    std::string message;
    public:
    InvalidInput(std::string msg): message(msg){}
    const char* what() const noexcept;
};