#include "engines.h"

class Vehicles{
protected:
//metric assumed 
double weight;
double lenght;
double width;
double height;
int seats;
enum wheels{
    TWO=2,
    THREE,
    FOUR
}wheel_count;
};

class Electric: virtual public Vehicles{
    int battery_capacity;
};

class  Fossil: virtual public Vehicles{
    Engine* engine;
    public:
    virtual ~Fossil();
};

class Hybrid: public Electric, public Fossil{

};