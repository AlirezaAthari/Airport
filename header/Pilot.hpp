#ifndef PILOT_H
#define PILOT_H

#include <iostream>
#include <vector>

class Pilot
{
protected:
    std::string id;
    char name[25];
    unsigned int age;
    Pilot(std::string , std::string , unsigned int);
    Pilot();
public:
    void setAge(unsigned int);
    unsigned int getAge();
    void setName(std::string);
    std::string getName();
    std::string getId();
    virtual void showInfo();
    virtual void setInfo(std::vector<Pilot *> & , const std::string &);
};


#endif