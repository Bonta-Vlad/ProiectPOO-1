#include "menu.h"
#include <algorithm>
#include <iostream>
#include "exceptions.h"

Menu* Menu::Instance= nullptr;
int Menu::Active=1;

Menu* Menu::init(){
    if(!Instance){
        Instance= new Menu();
    }
    return Instance;
}
Menu::~Menu(){
    data.clear();
    delete Instance;
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
    int target;
    std::cin>> target;
    for(auto& i: data){
        if(i->get_id()== target){
            data.erase(std::find(data.begin(), data.end(), i));
        }
    }
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

    int option;
    try{
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
    }
    }catch(InvalidInput& e){
        std::cout<<e.what()<<std::endl;
        std::cin.get();
    }
}