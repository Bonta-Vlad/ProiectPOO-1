#include "vehicles.h"
#include <iostream>

int Vehicles::gid= 100;

int Vehicles::get_id() const{
    return id;
}

void Fossil::print() const{
    std::cout<<"ID:"<<id<<"/nEngine displacement: "<<engine->displacement()<<"/nWheel count:"<<wheel_count<<std::endl;
}

void Electric::print() const{
    std::cout<<"ID:"<<id<<"/nBattery capacity: "<<battery_capacity<<"/nWheel count:"<<wheel_count<<std::endl;
}

void Hybrid::print() const{
    std::cout<<"ID:"<<id<<"/nBattery capacity: "<<"/nEngine displacement: "<<engine->displacement()<<battery_capacity<<"/nWheel count:"<<wheel_count<<std::endl;
}