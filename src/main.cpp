#include <iostream>
#include "Airport.hpp"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    Airport * airport;
    airport = Airport::getInstance("Hamedan");
    airport->showMenu();
    airport->~Airport();
    return 0;
}

