#include <vector>
#include "vehicles.h"
class Menu{
    static Menu* Instance;
    std::vector<Vehicles*> data;
    Menu();
    public:
    static Menu* init();
    ~Menu();
    
};