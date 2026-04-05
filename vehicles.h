#include "engines.h"
#include <ostream>

class Vehicles{
protected:
static int gid;
//metric assumed 
double weight;
double lenght;
int seats;
int id;
int wheel_count;
Vehicles(double _weight, double _lenght, int _seats, int _wheel_count):weight(_weight),lenght(_lenght),seats(_seats),wheel_count(_wheel_count){}
public:
virtual ~Vehicles(){}
int get_id() const;
virtual void print() const= 0;

};

class Electric: virtual public Vehicles{
    protected:
    int battery_capacity;
    public:
    virtual void print() const override;
    virtual ~Electric(){}
    Electric(double _weight, double _lenght, int _seats, int _wheel_count,int _battery_capacity):Vehicles(_weight, _lenght, _seats, _wheel_count),battery_capacity(_battery_capacity){}
};

class  Fossil: virtual public Vehicles{
    protected:
    Engine* engine;
    public:
    virtual ~Fossil(){ delete engine; }
    virtual void print() const override;
    Fossil(double _weight, double _lenght, int _seats, int _wheel_count, Engine* _engine):Vehicles(_weight, _lenght, _seats, _wheel_count),engine(_engine){}
};

class Hybrid: public Electric, public Fossil{
    virtual void print() const override;
    public:
    Hybrid(double _weight, double _lenght, int _seats, int _wheel_count, Engine* _engine, int _battery_capacity):Vehicles(_weight, _lenght, _seats, _wheel_count),Fossil(_weight,_lenght,_seats,_wheel_count,_engine),Electric(_weight, _lenght, _seats, _wheel_count, _battery_capacity){}
};