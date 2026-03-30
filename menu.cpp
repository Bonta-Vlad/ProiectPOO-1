#include "menu.h"

Menu* Menu::Instance= nullptr;

Menu* Menu::init(){
    if(!Instance){
        Instance= new Menu();
    }
    return Instance;
}

Menu::~Menu(){
    for (Vehicles* i : data) {
        delete i;
    }
    data.clear();
}