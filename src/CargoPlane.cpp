#include "CargoPlane.hpp"
#include "Functions.hpp"

CargoPlane::CargoPlane(std::string id, unsigned int weight) : Plane(id)
{
    setWeight(weight);
}

CargoPlane::CargoPlane() : Plane()
{
    weight = 0;
}

unsigned int CargoPlane::getWeight()
{
    return weight;
}

void CargoPlane::showInfo()
{
    std::cout << "Id : " << getId() <<std::endl;
    std::cout << "Weight : " << getWeight() << std::endl;
}

void CargoPlane::setWeight(unsigned int w)
{
    if (w < 10000 && w > 0)
    {
        weight = w;
    }
    else
        throw std::invalid_argument("invalid weight too much or negative value!");
}

void CargoPlane::setInfo(std::vector<Plane *> &planes, const std::string &editId)
{
    Plane::setInfo(planes, editId);
    if (editId == "No Id")
    {
        id = id + "CP";
    }
    std::cout << "Weight : ";
    unsigned int w;
    std::cin >> w;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    setWeight(w);
    while (1)
    {
        system("clear");
        this->showInfo();
        std::cout << "Are you sure to add this plane? (1.yes 2.no) : ";
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
                planes.push_back(this);
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