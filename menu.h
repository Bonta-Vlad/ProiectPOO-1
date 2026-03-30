#include <vector>
#include "vehicles.h"
class Menu{
    static int Active;
    static Menu* Instance;
    std::vector<Vehicles*> data;
    Menu();
    public:
    static Menu* init();
    ~Menu();
    public:
    int status() const;
    void options();
    void quit();
    void add_vehicle();
    void list_vehicles() const;
    void remove_vehicle();
};