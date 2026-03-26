#include "engines.h"

double Reciprocating::displacement() const{
                                      //pi(bore/2)^2
    return stroke_lenght*cylinder_count*2*acos(0.0)*pow((bore/2),2);
}