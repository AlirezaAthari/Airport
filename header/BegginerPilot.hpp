#ifndef BEGGINERPILOT_H
#define BEGGINERPILOT_H

#include <iostream>
#include "Pilot.hpp"

class BegginerPilot : public Pilot
{
private:
    unsigned int FlightsNumber;
public:
    BegginerPilot(std::string , std::string , unsigned int , unsigned int);
    BegginerPilot();
    void setFlightsNumber(unsigned int);
    unsigned int getFlightsNumber();
    virtual void setInfo(std::vector<Pilot *> &, const std::string &);
    virtual void showInfo();
};


#endif