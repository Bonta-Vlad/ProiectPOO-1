#include "engines.h"
#include <cmath>
//displacement formula taken from wikipedia
double Reciprocating::displacement() const{
                                      //pi(bore/2)^2
    return stroke_length*cylinder_count*2*acos(0.0)*pow((bore/2),2);
}

double Rotary::displacement() const{
    return chamber_count*chamber_volume*rotor_count;
}

int Reciprocating::get_stokes()const{return strokes;}
int Reciprocating::get_config()const{return config;}