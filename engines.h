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
    virtual ~Engine();
    virtual double displacement() const=0;
};

class Reciprocating: public Engine{
    enum strokes{
        TWO=2,
        FOUR=4
    }strokes;
    enum config{
        INLINE,
        BOXER,
        V,
        W,
        RADIAL,
    }config;
    unsigned int cylinder_count;
    double bore;
    double stroke_length;
    public:
    double displacement() const override;
    Reciprocating(std::string _lubricant, enum ignition _ignition, enum strokes _strokes, enum config _config, unsigned int _cylinder_count, double _bore, double _stroke_length);
};