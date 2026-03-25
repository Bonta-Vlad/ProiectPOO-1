#include <cmath>
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

class Reciprocating: public Engine{
    enum{
        TWO,
        FOUR
    }strokes;
    enum{
        INLINE,
        BOXER,
        V,
        W,
        RADIAL,
    }config;
    unsigned int cylinder_count;
    double bore;
    double stroke_lenght;
    public:
    double displacement() const override;
};
double Reciprocating::displacement() const{
    //                                  pi(bore/2)^2
    return stroke_lenght*cylinder_count*2*acos(0.0)*pow((bore/2),2);
}
//This is for pistonless rotary engines, use the Reciprocating class for raidal engines
class Rotary: public Engine{
    unsigned int chamber_count;
};