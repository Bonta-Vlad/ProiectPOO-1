#include <string>

class Engine{
    protected:
    // specify the exact lubricant viscocity required in accordance with SAE J300 https://en.wikipedia.org/wiki/SAE_J300
    std::string lubricant;
    enum ignition{
        SPARK,
        COMPRESSION
    }ignition;
    Engine(std::string _lubricant, enum ignition _ignition):lubricant(_lubricant),ignition(_ignition){}
    public:
    virtual ~Engine(){}
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
    Reciprocating(std::string _lubricant, enum ignition _ignition, enum strokes _strokes, enum config _config, unsigned int _cylinder_count, double _bore, double _stroke_length):Engine(_lubricant, _ignition),strokes(_strokes),config(_config),cylinder_count(_cylinder_count),bore(_bore),stroke_length(_stroke_length){}
};

class Rotary: public Engine{
    //volume for one of the engines chambers
    double chamber_volume;
    int chamber_count;
    int rotor_count;
    public:
    double displacement() const override;
    Rotary(std::string _lubricant, enum ignition _ignition, double _chamber_volume, int chamber_count, int _rotor_count):Engine(_lubricant, _ignition),chamber_volume(_chamber_volume),chamber_count(chamber_count),rotor_count(_rotor_count){}
};