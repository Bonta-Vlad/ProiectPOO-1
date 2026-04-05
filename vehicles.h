#include "engines.h"
#include <ostream>

class Vehicles{
protected:
static int gid;
//metric assumed 
double weight;
double lenght;
double width;
double height;
int seats;
int id;
enum wheels{
    TWO=2,
    THREE,
    FOUR
}wheel_count;
public:
virtual ~Vehicles();
int get_id() const;
virtual void print() const= 0;

};

class Electric: virtual public Vehicles{
    protected:
    int battery_capacity;
    public:
    virtual void print() const override;
    virtual ~Electric();
};

class  Fossil: virtual public Vehicles{
    protected:
    Engine* engine;
    public:
    virtual ~Fossil();
    virtual void print() const override;
};

class Hybrid: public Electric, public Fossil{
    virtual void print() const override;
};