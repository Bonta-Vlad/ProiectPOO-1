#include "menu.h"

int main(){

    Menu* menu= Menu::init();

    while(menu->status()){
        menu->options();
    }

    return 0;
}