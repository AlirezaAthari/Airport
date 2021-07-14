#ifndef ADVANCEDPILOT_H
#define ADVANCEDPILOT_H

#include <iostream>
#include "Pilot.hpp"
#include <vector>

class AdvancedPilot : public Pilot
{
private:
    unsigned int degree;
public:
    void setDegree(unsigned int);
    unsigned int getDegree();
    AdvancedPilot(std::string ,std::string , unsigned int , unsigned int);
    AdvancedPilot();
    virtual void showInfo();
    virtual void setInfo(std::vector<Pilot *> &, const std::string &);
};


#endif