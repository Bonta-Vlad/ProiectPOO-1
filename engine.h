#include <string>

class Engine{
    protected:
    std::string lubricant;
    std::string fuel;
    enum{
        SPARK,
        COMPRESSION
    }ignition;
    public:
    virtual double displacement() const=0;
};
