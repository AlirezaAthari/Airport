#include "BegginerPilot.hpp"
#include "Functions.hpp"
BegginerPilot::BegginerPilot(std::string name, std::string id, unsigned int age, unsigned int fn) : Pilot(id, name, age)
{
    this->id = id;
    setFlightsNumber(fn);
}

BegginerPilot::BegginerPilot() : Pilot()
{
    FlightsNumber = 0;
}

void BegginerPilot::showInfo()
{
    Pilot::showInfo();
    std::cout << "Flights Number : " << FlightsNumber << std::endl;
}

void BegginerPilot::setFlightsNumber(unsigned int fn)
{
    if (fn < 100)
    {
        FlightsNumber = fn;
    }
    else
        throw std::invalid_argument("This Pilot should be in advanced level");
}

unsigned int BegginerPilot::getFlightsNumber()
{
    return FlightsNumber;
}

void BegginerPilot::setInfo(std::vector<Pilot *> &pilots, const std::string &editId)
{
    Pilot::setInfo(pilots, editId);
    if (editId == "No Id")
    {
        id = id + "BP";
    }
    std::cout << "Number of Flights : ";
    unsigned int fn;
    std::cin >> fn;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    setFlightsNumber(fn);
    while (1)
    {
        system("clear");
        this->showInfo();
        std::cout << "Are you sure to add this pilot? (1.yes 2.no) : ";
        unsigned int choose;
        std::cin >> choose;
        if (std::cin.fail())
        {
            std::cin.clear();
            ignoreLine();
        }
        if (choose == 1)
        {
            if (editId == "No Id")
            {
                pilots.push_back(this);
            }
            std::cout << "Successfully Done! Press any key to continue.\n";
            std::cin.get();
            break;
        }
        else if (choose == 2)
        {
            std::cout << "Adding Canceled! Press any key to continue.\n";
            std::cin.get();
            break;
        }
        else
        {
            std::cerr << "invalid choose";
        }
        std::cin.ignore();
    }
    std::cin.ignore();
}