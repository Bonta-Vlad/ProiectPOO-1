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