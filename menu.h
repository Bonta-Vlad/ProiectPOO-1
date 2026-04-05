#include <memory>
#include <vector>
#include "vehicles.h"
class Menu{
    static int Active;
    static Menu* Instance;
    std::vector<Vehicles*> data;
    Menu(){}
    void add_fossil();
    void add_electric();
    void add_hybrid();
    public:
    static Menu* init();
    ~Menu(){ 
        delete Instance;
        for (auto i : data) {
            delete i;
        }
        data.clear();
    }
    Menu(const Menu& _menu)= delete;
    int status() const;
    void options();
    void quit();
    void add_vehicle();
    void list_vehicles() const;
    void remove_vehicle();
    Engine* build_engine();
};