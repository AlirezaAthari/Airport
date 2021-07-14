#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <vector>
#include "Pilot.hpp"
#include "Plane.hpp"
#include "Flight.hpp"
#include "AdvancedPilot.hpp"
#include <algorithm>
#include <limits>
#include "BegginerPilot.hpp"

class Airport
{
private:
    static Airport *airport;
    Airport(std::string);
    std::string name;
    std::vector<Plane *> planes;
    std::vector<Pilot *> pilots;
    std::vector<Flight *> flights;

public:
    static Airport *getInstance(const std::string &); //by name
    std::string getName() const;
    void showMenu();
    void showInfo();
    void editInfo();
    void addPlane();
    void addPilot();
    void addFlight();
    ~Airport();
};

template <class T>
void showItems(std::vector<T *> &v)
{
    if (v.size() == 0)
    {
        throw std::invalid_argument("No Item Press any key to back\n");
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        v.at(i)->showInfo();
        std::cout << "-----------------------------------------\n";
    }
    std::cout << "press any key to continue" << std::endl;
    std::cin.get();
    std::cin.ignore();
}

template <class T>
void removeItem(std::vector<T *> &v, const std::string &id)
{
    std::cin.ignore();
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v.at(i)->getId() == id)
        {
            system("clear");
            v.at(i) = nullptr;
            v.erase(std::remove(v.begin(), v.end(), nullptr), v.end());
            std::cout << "Remove Successfully!" << std::endl;
            std::cin.get();
            std::cin.ignore();
            return;
        }
    }
    throw(std::invalid_argument("Not Found!"));
}
template <class T>
void editItems(std::vector<T *> &v, const std::string &id)
{
    std::cin.ignore();
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v.at(i)->getId() == id)
        {
            system("clear");
            v.at(i)->setInfo(v,id);
            std::cout << "Edit Successfully!" << std::endl;
            std::cin.get();
            std::cin.ignore();
            return;
        }
    }
    throw std::invalid_argument("Not Found!") ;
}

#endif