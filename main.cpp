#include "menu.h"

int main(){

    Menu* menu= Menu::init();

    while(menu->status()){
        menu->options();
    }

    delete menu;
    return 0;
}