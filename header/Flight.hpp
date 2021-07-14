#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <vector>

class Flight
{
private:
    std::string id;
    std::string planeId;
    std::string pilotId;
    std::string destination;
    std::string origin;
public:
    Flight(std::string ,std::string ,std::string ,std::string ,std::string);
    Flight();
    std::string getOrigin();
    std::string getDistination();
    std::string getPlaneId();
    std::string getPilotId();
    std::string getId();
    void showInfo();
    void setInfo(std::vector<Flight *> &, const std::string &);
};


#endif