// @Author= Halil Faruk Karagöz 
// No : 150180014
#include "Mission.h"
#include <iostream>
using namespace std;

Mission ::Mission() : name("AA-00")
{
    cost = 0;
    missionNumber = 0;
    faultProbability = 0;
    completed = false;
    PassengersNumber = 0;
    crewNumber = 0;
    Passengers = NULL;
    crew = NULL;
}

Mission ::Mission(string inname, int incost, int infaultProbability, int inmissionNumber, bool incompleted)
    : cost(incost), faultProbability(infaultProbability), missionNumber(inmissionNumber), completed(incompleted)
{
    Passengers = NULL;
    crew = NULL;
    crewNumber = 0;
    PassengersNumber = 0;
    bool string_is_valid = true;
    if (inname.length() != 5)
        string_is_valid = false;
    if (inname[0] < 64 || inname[0] > 90)
        string_is_valid = false;
    if (inname[1] < 64 || inname[1] > 90)
        string_is_valid = false;
    if (inname[2] != 45)
        string_is_valid = false;
    if (inname[3] < 47 || inname[3] > 57)
        string_is_valid = false;
    if (inname[4] < 47 || inname[4] > 57)
        string_is_valid = false;
    if (string_is_valid)
        name = inname;
    else
    {
        cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        name = "AA-00";
    }
}

Mission ::Mission(const Mission &m) : name(m.name), cost(m.cost), faultProbability(m.faultProbability), missionNumber(m.missionNumber), completed(m.completed)
{
    crewNumber = m.crewNumber;
    PassengersNumber = m.PassengersNumber;
    Passengers = new Passenger *[m.PassengersNumber];
    crew = new Astronaut *[m.crewNumber];
    for (int i = 0; i < PassengersNumber; i++)
    {
        Passenger* node = new Passenger(*(m.Passengers[i]));
        Passengers[i] = node;
    }
    for (int i = 0; i < crewNumber; i++)
    {
        Astronaut* node= new Astronaut(*(m.crew[i]));
        crew[i] = node;
    }
}

Mission ::~Mission()
{
    for (int i = 0; i < PassengersNumber; i++)
        delete Passengers[i];
    delete[] Passengers;
    for (int i = 0; i < crewNumber; i++)
        delete crew[i];
    delete[] crew;
}

void Mission ::operator+=(Passenger *p)
{
    if (p->getThicket())
    {
        Passenger **newP = new Passenger *[PassengersNumber + 1];
        for (int i = 0; i < PassengersNumber; i++)
        {
            newP[i] = Passengers[i];
        }
        Passenger* newNode = new Passenger(*p);
        newP[PassengersNumber++] = newNode;
        if (PassengersNumber > 0)
        {
            delete[] Passengers;
        }
        Passengers = newP;
    }
    else
    {
        cout << "Passenger " << p->getName() << " " << p->getSurname() << " does not have a valid ticket!";
    }
}

void Mission ::operator+=(Astronaut *a)
{
    Astronaut **newA = new Astronaut *[crewNumber + 1];
    for (int i = 0; i < crewNumber; i++)
    {
        newA[i] = crew[i];
    }

    if (crewNumber > 0)
    {
        delete[] crew;
    }
    Astronaut* newNode = new Astronaut(*a);
    newA[crewNumber++] = newNode;
    crew = newA;
}

bool Mission ::executeMission()
{
    int random = std::rand() % 100;
    if (random > faultProbability)
    {
        completed = true;
        cout << "MISSION " << name << " SUCCESSFUL!" << endl;
        for (int i = 0; i < crewNumber; i++)
        {
            crew[i]->completeFlight();
            crew[i]->writeCompletedMessage();
        }
        return true;
    }
    else
    {
        cout << "MISSION " << name << " FAILED!" << endl;
        return false;
    }
}

int Mission ::calculateProfit(int price)
{
    if (completed)
    {
        return PassengersNumber * price - cost;
    }
    else
        return cost;
}

string Mission ::getName() const { return name; }
int Mission ::getCrewNumber() const { return crewNumber; }
int Mission ::getPassengerNumber() const { return PassengersNumber; }
Passenger* Mission ::  getIndexedPassanger(int i) const{return Passengers[i]; }
Astronaut* Mission ::  getIndexedCrew(int i) const { return crew[i];}
int Mission :: getMissionNumber() const {return missionNumber;}
int Mission :: getCost() const {return cost;}
void Mission ::setName(string inname) { name.assign(inname); }
void Mission ::setMissionNumber(int i) { missionNumber = i; }