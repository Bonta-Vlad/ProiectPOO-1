#include "menu.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "exceptions.h"

Menu* Menu::Instance= nullptr;
int Menu::Active=1;

Menu* Menu::init(){
    if(!Instance){
        Instance= new Menu();
    }
    return Instance;
}
int Menu::status() const{
    return Active;
}
void Menu::quit(){
    Active=0;
}

void Menu::list_vehicles() const{
    for (auto& i : data) {
    i->print();
    }
}

void Menu::remove_vehicle(){
    list_vehicles();
    std::cout<<"Remove vehicle with id: ";
    int target, poz= -1;
    std::cin>> target;
    for(unsigned int i= 0;i< data.size(); i++){
        if(data[i]->get_id()== target){
         poz= i;
         break;
        }
    }
    if (poz >=0){
        //don't need the returned iterator, but it's a nodiscard function.
        auto ignore =std::remove(data.begin(),data.end(),poz);
        data.pop_back();
    }
}

void Menu::add_vehicle(){
    int retry;
    int option;
    do {
    retry=0;
    try {
        std::cout<<"\033[2J\033[1;1H";
        std::cout<<"Select the Vehicle type:/n";
        std::cout<<"0 - Fossil Fuel/n";
        std::cout<<"1 - Electric/n";
        std::cout<<"2 - Hybrid/n";
        std::cin>>option;
    } catch (InvalidInput& e)  {
        std::cout<<e.what()<<std::endl;
        retry=1;
        std::cin.get();
    }

    }while (retry);
}

void Menu::options(){
    //clear screen via ANSI escape codes
    //*should* work across OSes
    std::cout<<"\033[2J\033[1;1H";
    std::cout<<"Choose an option:/n";
    std::cout<<"0 - Quit/n";
    std::cout<<"1 - Add a vehicle/n";
    std::cout<<"2 - List current vehicles/n";
    std::cout<<"3 - Remove a vehicle/n";

    
    try{
    int option;
    std::cin>>option;
    switch (option){
    case 0:
    quit();break;
    case 1:
    add_vehicle();break;
    case 2:
    list_vehicles();break;
    case 3:
    remove_vehicle();break;
    default: throw InvalidInput("Invalid option! Valid options: [0-3] Got: " + std::to_string(option)) ; break;
    }
    }catch(InvalidInput& e){
        std::cout<<e.what()<<std::endl;
        std::cin.get();
    }
}