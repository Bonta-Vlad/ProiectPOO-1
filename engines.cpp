#include "engines.h"
#include <cmath>
double Reciprocating::displacement() const{
                                      //pi(bore/2)^2
    return stroke_length*cylinder_count*2*acos(0.0)*pow((bore/2),2);
}