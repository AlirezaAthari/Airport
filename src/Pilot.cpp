#include "Pilot.hpp"
#include <fstream>
#include "Functions.hpp"

Pilot::Pilot(std::string id, std::string name, unsigned int age)
{
    setAge(age);
    for (size_t i = 4; i < name.size(); i++)
    {
        this->name[i - 4] = name.at(i);
    }
    this->id = id;
}
Pilot::Pilot()
{
    this->age = 0;
    this->id = "No Id";
    static_cast<std::string>(this->name) = "No Name";
}

std::string Pilot::getName()
{
    return name;
}

std::string Pilot::getId()
{
    return id;
}

unsigned int Pilot::getAge()
{
    return age;
}

void Pilot::setAge(unsigned int age)
{
    if (age > 18 && age < 50)
    {
        this->age = age;
    }
    else
        throw std::invalid_argument("Unacceptable age!");
}

void Pilot::showInfo()
{
    std::cout << "Pilot Info :\n"
              << "Id : " << getId() << "\nName : " << getName() << "\nAge : " << getAge() << std::endl;
}

void Pilot::setInfo(std::vector<Pilot *> &pilots, const std::string &editId)
{
    std::cout << "Enter Pilot Information : " << std::endl;
    if (editId == "No Id")
    {
        id = std::to_string(idGenerator(pilots));
        std::stringstream oss;
        oss << std::setw(2) << std::setfill('0') << id;
        id = oss.str();
    }
    std::cout << "Name : ";
    std::cin.get(name, 25, '\n');
    std::cout << "Age : ";
    unsigned int a;
    std::cin >> a;
    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
    }
    setAge(a);
}