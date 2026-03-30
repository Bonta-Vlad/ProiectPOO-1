#include "vehicles.h"

int Vehicles::gid= 100;

int Vehicles::get_id() const{
    return id;
}

Fossil::~Fossil(){
    delete engine;
}