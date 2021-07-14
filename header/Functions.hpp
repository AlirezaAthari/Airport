#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

void ignoreLine();

template <typename T>
int idGenerator(std::vector<T *> v)
{
    if (v.size() == 0)
    {
        return 0;
    }
    
    int id = stoi(v.at(v.size()-1)->getId());
    for (size_t i = 0; i < v.size(); i++)
    {
        if (stoi(v.at(i)->getId()) >= id)
        {
            id = stoi(v.at(i)->getId()) + 1;
        }
        
    }
    return id;

}

