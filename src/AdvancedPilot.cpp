#include "AdvancedPilot.hpp"
#include "Functions.hpp"
//amir asgahrian:just for test for github ;
AdvancedPilot::AdvancedPilot(std::string id , std::string name, unsigned int age, unsigned int degree) : Pilot(id, name, age)
{
    this->id = id;
    setDegree(degree);
}

AdvancedPilot::AdvancedPilot() : Pilot()
{
    degree = 0;
}

void AdvancedPilot::setDegree(unsigned int degree)
{
    if (degree == 1 || degree == 2)
    {
        this->degree = degree;
    }
    else
        throw std::invalid_argument("degree most be 1 or 2.");
}

void AdvancedPilot::showInfo()
{
    Pilot::showInfo();
    std::cout << "Degree : " << degree << std::endl;
}

unsigned int AdvancedPilot::getDegree()
{
    return degree;
}

void AdvancedPilot::setInfo(std::vector<Pilot *> &pilots, const std::string &editId)
{
    Pilot::setInfo(pilots, editId);
    if (editId == "No Id")
    {
        id = id + "AP";
    }
    std::cout << "Degree : ";
    unsigned int d;
    std::cin >> d;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    setDegree(d);
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
