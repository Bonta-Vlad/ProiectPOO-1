#include <string>

class Engine{
    protected:
    // specify the exact lubricant viscocity required in accordance with SAE J300 https://en.wikipedia.org/wiki/SAE_J300
    std::string lubricant;
    std::string ignition;
    Engine(std::string _lubricant, std::string _ignition):lubricant(_lubricant),ignition(_ignition){}
    public:
    virtual ~Engine(){}
    virtual double displacement() const=0;
};

class Reciprocating: public Engine{
    unsigned int cylinder_count;
    double bore;
    double stroke_length;
    public:
    int get_stokes() const;
    int get_config() const;
    double displacement() const override;
    Reciprocating(std::string& _lubricant, std::string _ignition, unsigned int _cylinder_count, double _bore, double _stroke_length):Engine(_lubricant, _ignition),cylinder_count(_cylinder_count),bore(_bore),stroke_length(_stroke_length){}
};

class Rotary: public Engine{
    //volume for one of the engines chambers
    double chamber_volume;
    int chamber_count;
    int rotor_count;
    public:
    double displacement() const override;
    Rotary(std::string& _lubricant, std::string _ignition, double _chamber_volume, int chamber_count, int _rotor_count):Engine(_lubricant, _ignition),chamber_volume(_chamber_volume),chamber_count(chamber_count),rotor_count(_rotor_count){}
};