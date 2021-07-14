#ifndef PASSENGERPLANE_H
#define PASSENGERPLANE_H

#include "Plane.hpp"
#include <iostream>

class PassengerPlane : public Plane
{
private:
    unsigned int passengersNumber;
public:
    PassengerPlane(std::string , unsigned int);
    PassengerPlane();
    unsigned int getPassengersNumber();
    void setPassengersNumber(unsigned int);
    virtual void setInfo(std::vector <Plane *> &, const std::string &);
    unsigned int getNumber();
    virtual void showInfo();
};

#endif