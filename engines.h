#include <string>

class Engine{
    protected:
    // specify the exact lubricant viscocity required in accordance with SAE J300 https://en.wikipedia.org/wiki/SAE_J300
    std::string lubricant;
    enum ignition{
        SPARK,
        COMPRESSION
    }ignition;
    public:
    virtual double displacement() const=0;
    Engine(std::string _lubricant, enum ignition _ignition);
    Engine(Engine& other);
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