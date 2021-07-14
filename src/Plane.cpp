#include "Plane.hpp"
#include "Functions.hpp"


Plane::Plane(std::string id)
{
    this->id = id;
}

Plane::Plane()
{
    id = "No Id";
}

std::string Plane::getId()
{
    return id;
}

void Plane::showInfo()
{
    std::cout << "Plane info :" << '\n'
              << "id : " << getId() << std::endl;
}

void Plane::setInfo(std::vector<Plane *> &planes, const std::string &editId)
{
    std::cout << "Enter Plane Information : " << std::endl;
    if (editId == "No Id")
    {
        id = std::to_string(idGenerator(planes));
        std::stringstream oss;
        oss << std::setw(2) << std::setfill('0') << id;
        id = oss.str();
    }
}