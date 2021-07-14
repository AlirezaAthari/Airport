#include "PassengerPlane.hpp"
#include "Functions.hpp"

PassengerPlane::PassengerPlane(std::string id, unsigned int number) : Plane(id)
{
    setPassengersNumber(number);
}

PassengerPlane::PassengerPlane() : Plane()
{
    passengersNumber = 0;
}

void PassengerPlane::setPassengersNumber(unsigned int number)
{
    if (number < 500)
    {
        passengersNumber = number;
    }
    else
        throw std::invalid_argument("too much passengers!");
}

unsigned int PassengerPlane::getPassengersNumber()
{
    return passengersNumber;
}

unsigned int PassengerPlane::getNumber()
{
    return passengersNumber;
}

void PassengerPlane::showInfo()
{
    std::cout << "Id : " << getId() <<std::endl;
    std::cout << "Passenger numbers : " << getNumber() << std::endl;
}

void PassengerPlane::setInfo(std::vector<Plane *> &planes, const std::string &editId)
{
    Plane::setInfo(planes, editId);
    if (editId == "No Id")
    {
        id = id + "PP";
    }

    std::cout << "Number of Passengers : ";
    unsigned int number;
    std::cin >> number;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    setPassengersNumber(number);
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