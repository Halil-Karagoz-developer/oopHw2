#pragma once
#include "Person.h"
using namespace std;
class Mission{
    string name;
    int cost;
    int faultProbability;
    int missionNumber;
    bool completed;
    int PassengersNumber;
    int crewNumber;
    Passenger* Passengers;
    Astronaut* crew;
    public:
    //static variable
    static int numMissions;
    //constructures
    Mission();
    Mission(string,int = 0,int = 0,int = 0, bool = false);
    Mission(const Mission&);
    //Deconstructor
    ~Mission();
    //operator overloading
    void operator+=(Passenger*);
    void operator+=(Astronaut*);
    //other methods
    bool executeMission();
    int calculateProfit(int);
    // getters
    string getName()const ;

    // setters
    void setName(string inname);
};