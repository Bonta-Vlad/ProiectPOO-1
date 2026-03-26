#include "engine.h"

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