#include "Flight.hpp"
#include "Functions.hpp"

Flight::Flight(std::string id, std::string planeId, std::string pilotId, std::string destination, std::string origin)
{
    this->id = id;
    this->origin = origin;
    this->destination = destination;
    this->pilotId = pilotId;
    this->planeId = planeId;
}
Flight::Flight()
{
    this->id = "No Id";
    this->origin = "nothing";
    this->destination = "nothing";
    this->pilotId = "No Id";
    this->planeId = "No Id";
}
std::string Flight::getOrigin()
{
    return origin;
}
std::string Flight::getDistination()
{
    return destination;
}
std::string Flight::getPlaneId()
{
    return planeId;
}
std::string Flight::getPilotId()
{
    return pilotId;
}
std::string Flight::getId()
{
    return id;
}
void Flight::showInfo()
{
    std::cout << "Flight Info\nid : " << getId() << "\nPlane Id : " << getPlaneId() << "\nPilot Id" << getPilotId() << "\nOrigin : " << getOrigin() << "\nDestination : " << getDistination() << std::endl;
}

void Flight::setInfo(std::vector<Flight *> &flights, const std::string &editId)
{
    std::cout << "Enter Flight Information : " << std::endl;
    if (editId == "No Id")
    {
        id = std::to_string(idGenerator(flights));
        std::stringstream oss;
        oss << std::setw(2) << std::setfill('0') << id;
        id = oss.str();
        id = id + "F";
    }

    std::cout << "Plane Id : ";
    std::cin >> planeId;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    std::cout << "Pilot Id : ";
    std::cin >> pilotId;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    std::cout << "Origin : ";
    std::cin >> origin;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    std::cout << "Destination : ";
    std::cin >> destination;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    while (1)
    {
        system("clear");
        this->showInfo();
        std::cout << "Are you sure to add this flight? (1.yes 2.no) : ";
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
                flights.push_back(this);
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