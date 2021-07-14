#ifndef CARGOPLANE_H
#define CARGOPLANE_H

#include "Plane.hpp"
#include <iostream>

class CargoPlane : public Plane
{
private:
    unsigned int weight;
public:
    CargoPlane(std::string , unsigned int);
    void setWeight(unsigned int);
    CargoPlane();
    virtual void setInfo(std::vector <Plane *> &, const std::string &);
    unsigned int getWeight();
    virtual void showInfo();
};

#endif