#include <iostream>
#include "Agency.h"
using namespace std;

Agency ::Agency() : name(" "), cash(0), ticket_price(0) , crewNumber(0) , completedMissionNumber(0) , nextMissionNumber(0)
{
    crew = NULL;
    completedMissions = NULL;
    nextMissions = NULL;
}

Agency ::Agency(string inname, int incash, int inticket) : name(inname), cash(incash), crewNumber(0),
                                                         completedMissionNumber(0) , nextMissionNumber(0)
{
    crew = NULL;
    completedMissions = NULL;
    nextMissions = NULL;
    if (inticket < 0)
    {
        cout << "Ticket price can't be negative. It is set to 0." << endl;
        ticket_price = 0;
    }
    else
        ticket_price = inticket;
}

Agency ::Agency(const Agency &a) : name(a.name), cash(a.cash), crewNumber(a.crewNumber),
                    completedMissionNumber(a.completedMissionNumber), nextMissionNumber(a.nextMissionNumber)
                                   
{
    crew = NULL;
    completedMissions = NULL;
    nextMissions = NULL;
    crew = new Astronaut *[crewNumber];
    nextMissions = new Mission *[nextMissionNumber];
    completedMissions = new Mission *[completedMissionNumber];
    for (int i = 0; i < crewNumber; i++)
        crew[i] = a.crew[i];
    for (int i = 0; i < nextMissionNumber; i++)
        nextMissions[i] = a.nextMissions[i];
    for (int i = 0; i < completedMissionNumber; i++)
        completedMissions[i] = a.completedMissions[i];
}

Agency ::~Agency()
{
    for (int i = 0; i < crewNumber; i++)
        delete crew[i];
    delete[] crew;
    for (int i = 0; i < nextMissionNumber; i++)
        delete nextMissions[i];
    delete[] nextMissions;
    for (int i = 0; i < completedMissionNumber; i++)
        delete completedMissions[i];
    delete[] completedMissions;
}

void Agency ::addMission(Mission &m)
{
    Mission **newArray = new Mission *[nextMissionNumber + 1];
    for (int i = 0; i < nextMissionNumber; i++)
    {
        newArray[i] = nextMissions[i];
    }

    if (nextMissionNumber > 0)
    {
        delete[] nextMissions;
    }
    Mission *newM = new Mission(m);
    newM->setMissionNumber(nextMissionNumber + 1);
    newArray[nextMissionNumber++] = newM;
    nextMissions = newArray;
}

void Agency ::executeNextMission()
{
    if (nextMissionNumber > 0)
    {
        if (nextMissions[0]->executeMission())
        {
            Mission **newArray = new Mission *[completedMissionNumber + 1];
            for (int i = 0; i < completedMissionNumber; i++)
            {
                newArray[i] = completedMissions[i];
            }
            if (completedMissionNumber > 0)
            {
                delete[] completedMissions;
            }
            newArray[completedMissionNumber++] = nextMissions[0];
            completedMissions = newArray;
            cash += nextMissions[0]->calculateProfit(ticket_price);
            Mission **newArray1 = new Mission *[nextMissionNumber - 1];
            for (int i = 1; i < nextMissionNumber; i++)
            {

                newArray1[i - 1] = nextMissions[i];
            }
            if (nextMissionNumber > 0)
            {
                delete[] nextMissions;
            }
            nextMissionNumber--;
            nextMissions = newArray1;
        }
        else{
            cash -= nextMissions[0]->getCost();
        }
    }
    else
    {
        cout << "No available mission to execute!" << endl;
    }
}

ostream &operator<<(ostream &os, const Agency &a)
{
    os << "Agency name: " << a.getName() << ", Total cash: " << a.getCash() << ", Ticket Price: " << a.getTicketPrice() << endl;
    os << "Next Missions:" << endl;
    if (a.nextMissionNumber == 0)
    {
        os << "No missions available" << endl;
    }
    else
    {
        for (int i = 0; i < a.nextMissionNumber; i++)
        {
            os << "Mission number: " << a.nextMissions[i]->getMissionNumber() << " Mission name: " << a.nextMissions[i]->getName() << " Cost: "<< a.nextMissions[i]->getCost()  << endl;
        }
    }
    os << "Completed Missions:" << endl;
    if (a.completedMissionNumber == 0)
    {
        os << "No missions completed before." << endl;
    }
    else
    {
        for (int i = 0; i < a.completedMissionNumber; i++)
        {
            os << "Mission number: " << a.completedMissions[i]->getMissionNumber() << " Mission name: " << a.completedMissions[i]->getName() << " Cost: "<<a.completedMissions[i]->getCost() << endl;
        }
    }
    return os;
}

void Agency ::setTicketPrice(int inticket)
{
    if (inticket > 0)
        ticket_price = inticket;
    else
        ticket_price = 0;
}

string Agency ::getName() const { return name; }
int Agency ::getCash() const { return cash; }
int Agency ::getTicketPrice() const { return ticket_price; }
