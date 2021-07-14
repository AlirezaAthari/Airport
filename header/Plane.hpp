#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <vector>

class Plane
{
protected:
    std::string id;
    Plane(std::string);
    Plane();
public:
    std::string getId();
    virtual void showInfo();
    virtual void setInfo(std::vector <Plane *> & , const std::string &);
};

#endif