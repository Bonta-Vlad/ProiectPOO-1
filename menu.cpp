#include "menu.h"
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
    for (const auto& i : data) {
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
        data.erase(data.begin()+poz);
    }
}



void Menu::options(){
    //clear screen via ANSI escape codes
    //*should* work across OSes
    std::cout<<"\033[2J\033[1;1H";
    std::cout<<"Choose an option:\n";
    std::cout<<"0 - Quit\n";
    std::cout<<"1 - Add a vehicle\n";
    std::cout<<"2 - List current vehicles\n";
    std::cout<<"3 - Remove a vehicle\n";

    
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
Engine* Menu::build_engine(){
    std::cout<<"Building an engine:\n";
    Engine* t_engine;
    int option;
    std::cin>>option;
    if(option==1){
        int count;double bore,stroke;
        std::cin>>count>>bore>>stroke;
        std::string lubricant;
        getline(std::cin,lubricant);
        t_engine= new Reciprocating(lubricant,"spark",count,bore,stroke);
    }else if (option==2) {
        int chamber,rotor;double volume;
        std::cin>>volume>>chamber>>rotor;
        std::string lubricant;
        getline(std::cin,lubricant);
        t_engine= new Rotary(lubricant,"spark",volume,chamber,rotor);
    }

    return t_engine;
}
void Menu::add_electric(){
    std::cout<<"\033[2J\033[1;1H";
    std::cout<<"Adding an electric vehicle:\n";
    double weight,length;
    int whe,seats,battery;
    std::cin>>weight>>length>>seats>>whe>>battery;
    Electric* a_vehicle= new Electric(weight,length,seats,whe,battery);
    data.push_back(a_vehicle);
}

void Menu::add_fossil(){
    std::cout<<"\033[2J\033[1;1H";
    std::cout<<"Adding a fossil fuel vehicle:\n";
    double weight,length;
    int whe,seats;
    std::cin>>weight>>length>>seats>>whe;
    Fossil* a_vehicle = new Fossil(weight,length,seats,whe,build_engine());
    data.push_back(a_vehicle);
}

void Menu::add_hybrid(){
    std::cout<<"\033[2J\033[1;1H";
    std::cout<<"Adding a hybrid vehicle:\n";
    double weight,length;
    int whe,seats,battery;
    std::cin>>weight>>length>>seats>>whe>>battery;
    Fossil* a_vehicle = new Hybrid(weight,length,seats,whe,build_engine(),battery);
    data.push_back(a_vehicle);
}

void Menu::add_vehicle(){
    int retry;
    int option;
        std::cout<<"\033[2J\033[1;1H";
        std::cout<<"Select the Vehicle type:\n";
        std::cout<<"0 - Fossil Fuel\n";
        std::cout<<"1 - Electric\n";
        std::cout<<"2 - Hybrid\n";
    do {
    retry=0;
    try {
        std::cin>>option;
        switch (option) {
        case 0: add_fossil() ;break;
        case 1: add_electric() ;break;
        case 2: add_hybrid() ;break;
        default: throw InvalidInput("Invalid option! Valid options: [0-2] Got: " + std::to_string(option)) ; break;
        }
    } catch (InvalidInput& e)  {
        std::cout<<e.what()<<std::endl;
        retry=1;
        std::cin.get();
    }

    }while (retry);
}