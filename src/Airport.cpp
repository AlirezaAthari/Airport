#include "Airport.hpp"
#include "CargoPlane.hpp"
#include "PassengerPlane.hpp"
#include "AdvancedPilot.hpp"
#include "BegginerPilot.hpp"
#include <fstream>
#include "Functions.hpp"
#include <iomanip>
#include "stdlib.h"

Airport *Airport::airport = nullptr;
Airport::Airport(std::string name)
{
    this->name = name;

     std::ifstream in("../AirportData/Pilots.txt", std::ios::in);
    if (!in.is_open())
    {
        std::cerr << "Could not find pilots.txt file\nNew changes did'nt save!\n";
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        if (in.eof())
        {
            break;
        }
        
        std::string id;
        unsigned int age;
        char name[29];
        in >> id;
        in.get(name , 29);
        in >> age;
        if (!in.good())
        {
            break;
        }
        if (static_cast<std::string>(id).find("AP") != std::string::npos)
        {
            char degree[16];
            in.get(degree , 16);
            pilots.push_back(new AdvancedPilot(id , static_cast<std::string>(name) , age , std::stoi(static_cast<std::string>(degree))));
        }
        if (static_cast<std::string>(id).find("BP") != std::string::npos)
        {
            char flightsNumber[16];
            in.get(flightsNumber , 16);
            pilots.push_back(new BegginerPilot(id , static_cast<std::string>(name) , age , std::stoi(static_cast<std::string>(flightsNumber))));
        }
        if (!in.good())
        {
            break;
        }
        in.ignore();
        
        
    }

    in.close();
    in.open("../AirportData/Planes.txt", std::ios::in);
    if (!in.is_open())
    {
        std::cerr << "Could not find planes.txt file\nNew changes did'nt save!\n";
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (in.eof())
        {
            break;
        }
        
        char id[8];
        in.get(id , 8);
        size_t found = static_cast<std::string>(id).find("CP");
        if (found != std::string::npos)
        {
            char weight[12];
            in.get(weight , 10);
            planes.push_back(new CargoPlane(id , std::stoi(static_cast<std::string>(weight))));
        }
        found = static_cast<std::string>(id).find("PP");
        if (found != std::string::npos)
        {
            char passengersNumber[10];
            in.get(passengersNumber , 10);
            planes.push_back(new PassengerPlane(id , std::stoi(static_cast<std::string>(passengersNumber))));
        }
        if (!in.good())
        {
            break;
        }
        in.ignore();
        
        
    }

    in.close();
 }

Airport *Airport::getInstance(const std::string &name)
{
    if (airport == nullptr)
    {
        airport = new Airport(name);
    }
    return airport;
}

std::string Airport::getName() const
{
    return name;
}

void Airport::showMenu()
{
    std::cout << "Welcome to " << this->getName() << " airport!" << std::endl;
    std::cout << "Press Any key to continue.";
    std::cin.get();
    bool choosen = false;
    while (!choosen)
    {
        system("clear");
        unsigned int choose;
        std::cout << "Main Menu\n1.Show Info\n2.Edit Info\n3.Exit";
        std::cout << "\nEnter your choose : ";
        std::cin >> choose;
        system("clear");
        switch (choose)
        {
        case 1:
        {
            showInfo();
            break;
        }
        case 2:
        {
            editInfo();
            break;
        }
        case 3:
        {
            choosen = true;
            break;
        }
        default:
        {
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
        }
    }
}

void Airport::editInfo()
{
    bool choosen = false;
    while (!choosen)
    {
        system("clear");
        std::cout << "Edit Info\n1.Add\n2.Edit\n3.Remove\n4.Back\nChoose one option : ";
        unsigned int choose;
        std::cin >> choose;
        system("clear");
        switch (choose)
        {
        case 1:
        {
            std::cout << "Add" << std::endl
                      << "1.Pilot\n2.Plane\n3.Flight\nPress any key for back to menu : ";
            std::cin >> choose;
            system("clear");
            switch (choose)
            {
            case 1:
                addPilot();
                choosen = true;
                break;
            case 2:
                addPlane();
                choosen = true;
                break;
            case 3:
                addFlight();
                choosen = true;
                break;
            default:
                if (std::cin.fail())
                {
                    std::cin.clear();
                    ignoreLine();
                }
            }
            break;
        }
        case 2:
        {
            std::cout << "Edit" << std::endl
                      << "1.Pilot\n2.Plane\n3.Flight\nPress any key for back to menu : ";
            std::cin >> choose;
            system("clear");
            switch (choose)
            {
            case 1:
            {
                try
                {
                    showItems(pilots);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string pilot;
                std::cout << "Enter pilot's id to edit : ";
                std::cin >> pilot;
                system("clear");
                try
                {
                    editItems(pilots, pilot);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            case 2:
            {
                try
                {
                    showItems(planes);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string plane;
                std::cout << "Enter plane's id to edit : ";
                std::cin >> plane;
                system("clear");
                try
                {
                    editItems(planes, plane);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            case 3:
            {
                try
                {
                    showItems(flights);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string flight;
                std::cout << "Enter flight's id to edit : ";
                std::cin >> flight;
                system("clear");
                try
                {
                    editItems(flights, flight);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            default:
                if (std::cin.fail())
                {
                    std::cin.clear();
                    ignoreLine();
                }
            }
            break;
        }
        case 3:
        {
            std::cout << "Remove" << std::endl
                      << "1.Pilot\n2.Plane\n3.Flight\nPress any key for back to menu : ";
            std::cin >> choose;
            system("clear");
            switch (choose)
            {
            case 1:
            {
                try
                {
                    showItems(pilots);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string pilot;
                std::cout << "Enter pilot's id to remove : ";
                std::cin >> pilot;
                system("clear");
                try
                {
                    removeItem(pilots, pilot);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            case 2:
            {
                try
                {
                    showItems(planes);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string plane;
                std::cout << "Enter plane's id to remove : ";
                std::cin >> plane;
                system("clear");
                try
                {
                    removeItem(planes, plane);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            case 3:
            {
                try
                {
                    showItems(flights);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.get();
                    std::cin.ignore();
                    break;
                }
                std::string flight;
                std::cout << "Enter flight's id to removw : ";
                std::cin >> flight;
                system("clear");
                try
                {
                    removeItem(flights, flight);
                    choosen = true;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            default:
                if (std::cin.fail())
                {
                    std::cin.clear();
                    ignoreLine();
                }
            }
            break;
        }
        case 4:
            choosen = true;
            break;
        default:
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
    }
}

void Airport::showInfo()
{
    bool choosen = false;
    while (!choosen)
    {
        system("clear");
        std::cout << "Show Info\n1.Pilots\n2.Planes\n3.Flights\n4.Back\nChoose one option : ";
        unsigned int choose;
        std::cin >> choose;
        system("clear");
        switch (choose)
        {
        case 1:
            try
            {
                showItems(pilots);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
                std::cin.ignore();
                break;
            }
            choosen = true;
            break;
        case 2:
            try
            {
                showItems(planes);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
                std::cin.ignore();
                break;
            }
            choosen = true;
            break;
        case 3:
            try
            {
                showItems(flights);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
                std::cin.ignore();
                break;
            }
            choosen = true;
            break;
        case 4:
            choosen = true;
            break;
        default:
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
    }
}

void Airport::addPlane()
{
    while (1)
    {
        system("clear");
        if (planes.size() >= 20)
        {
            std::cout << "not enough space for new plane!\n";
            std::cin.get();
            std::cin.ignore();
            break;
        }
        std::cout << "Choose the type of Plane : \n1.Cargo \n2.Passenger\n3.Back to menu";
        std::cout << "\nEnter your choose : ";
        unsigned int choose;
        std::cin >> choose;
        system("clear");
        switch (choose)
        {
        case 1:
        {
            CargoPlane *cp = new CargoPlane();
            try
            {
                cp->setInfo(planes, "No Id");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n'
                          << "Press Any Key To Back Menu!\n";
                std::cin.get();
                std::cin.ignore();
                return;
            }
            break;
        }
        case 2:
        {
            PassengerPlane *pp = new PassengerPlane();
            try
            {
                pp->setInfo(planes, "No Id");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n'
                          << "Press Any Key To Back Menu!\n";
                std::cin.get();
                std::cin.ignore();
                return;
            }
            break;
        }
        case 3:
            return;
        default:
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
    }
}

void Airport::addPilot()
{
    while (1)
    {
        if (pilots.size() >= 20)
        {
            std::cout << "not enough space for new pilot!\n";
            std::cin.get();
            std::cin.ignore();
            break;
        }
        system("clear");
        std::cout << "Choose the type of Pilot : \n1.Advanced \n2.Begginer\n3.Back to menu";
        std::cout << "\nEnter your choose : ";
        unsigned int choose;
        std::cin >> choose;
        std::cin.ignore();
        system("clear");
        switch (choose)
        {
        case 1:
        {
            AdvancedPilot *ap = new AdvancedPilot();
            try
            {
                ap->setInfo(pilots, "No Id");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n'
                          << "Press Any Key To Back Menu!\n";
                std::cin.get();
                std::cin.ignore();
                return;
            }
            break;
        }
        case 2:
        {
            BegginerPilot *bp = new BegginerPilot();
            try
            {

                bp->setInfo(pilots, "No Id");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n'
                          << "Press Any Key To Back Menu!\n";
                std::cin.get();
                std::cin.ignore();
                return;
            }

            break;
        }
        case 3:
            return;
        default:
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
    }
}

void Airport::addFlight()
{
    while (1)
    {
        if (flights.size() >= 8)
        {
            std::cout << "not enough time for new flight!\n";
            std::cin.get();
            std::cin.ignore();
            break;
        }
        system("clear");
        std::cout << "Choose the option : \n1.Add Flight\n2.Back to menu";
        std::cout << "\nEnter your choose : ";
        unsigned int choose;
        std::cin >> choose;
        system("clear");
        switch (choose)
        {
        case 1:
        {
            Flight *f = new Flight();
            try
            {

                f->setInfo(flights, "No Id");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n'
                          << "Press Any Key To Back Menu!\n";
                std::cin.get();
                std::cin.ignore();
                return;
            }
            break;
        }
        case 2:
            return;
        default:
            if (std::cin.fail())
            {
                std::cin.clear();
                ignoreLine();
            }
        }
    }
}

Airport::~Airport()
{
    std::ofstream out("../AirportData/Pilots.txt", std::ios::out);
    if (!out.is_open())
    {
        std::cerr << "Could not find pilots.txt file\nNew changes did'nt save!\n";
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < pilots.size(); i++)
    {
        out << std::setw(8) << std::left << pilots.at(i)->getId() << std::setw(25) << pilots.at(i)->getName() << std::setw(8) << pilots.at(i)->getAge();
        AdvancedPilot *ap = dynamic_cast<AdvancedPilot *>(pilots.at(i));
        if (ap)
        {
            out << std::setw(8) << ap->getDegree() << std::endl;
        }
        BegginerPilot *bp = dynamic_cast<BegginerPilot *>(pilots.at(i));
        if (bp)
        {
            out << std::setw(8) << bp->getFlightsNumber() << std::endl;
        }
    }
    out.close();
    out.open("../AirportData/Planes.txt", std::ios::out);
    if (!out.is_open())
    {
        std::cerr << "Could not find planes.txt file\nNew changes did'nt save!\n";
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < planes.size(); i++)
    {
        out << std::setw(8) << std::left << planes.at(i)->getId();
        CargoPlane *cp = dynamic_cast<CargoPlane *>(planes.at(i));
        if (cp)
        {
            out << std::setw(5) << cp->getWeight() << std::endl;
        }
        PassengerPlane *pp = dynamic_cast<PassengerPlane *>(planes.at(i));
        if (pp)
        {
            out << std::setw(5) << pp->getPassengersNumber() << std::endl;
        }
    }
    out.close();

    for (size_t i = 0; i < planes.size(); i++)
    {
        planes.at(i) = nullptr;
        delete planes.at(i);
    }

    for (size_t i = 0; i < pilots.size(); i++)
    {
        pilots.at(i) = nullptr;
        delete pilots.at(i);
    }

    for (size_t i = 0; i < flights.size(); i++)
    {
        flights.at(i) = nullptr;
        delete flights.at(i);
    }
}