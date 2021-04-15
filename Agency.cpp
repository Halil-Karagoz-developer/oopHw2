#include <iostream>
#include "Agency.h"
using namespace std;

Agency :: Agency(): name(" "),cash(0),nextMissionNumber(0),completedMissionNumber(0), crewNumber(0),ticket_price(0){}

Agency :: Agency(string inname, int incash,int inticket):name(inname),cash(incash),nextMissionNumber(0),
completedMissionNumber(0), crewNumber(0)
{
    if(inticket < 0) ticket_price = 0;
    else ticket_price = inticket;    
}

Agency :: Agency(const Agency& a) : name(a.name), cash(a.cash),nextMissionNumber(a.nextMissionNumber),
completedMissionNumber(a.completedMissionNumber), crewNumber(a.crewNumber)
{
    crew = new Astronaut[crewNumber];
    nextMissions = new Mission[nextMissionNumber];
    completedMissions = new Mission[completedMissionNumber];
    for(int i = 0; i< crewNumber; i++) crew[i] = a.crew[i];
    for(int i = 0; i< nextMissionNumber; i++) nextMissions[i] = a.nextMissions[i];
    for(int i = 0; i< completedMissionNumber; i++) completedMissions[i] = a.completedMissions[i];
}

Agency :: ~Agency(){
    delete [] crew;
    delete [] nextMissions;
    delete [] completedMissions;
}

void Agency :: addMission(Mission& m){
    Mission* newArray = new Mission[nextMissionNumber+1];
    for(int i = 0; i< nextMissionNumber; i++) newArray[i] = nextMissions[i];
    delete [] nextMissions;
    Mission newM(m);
    newArray[nextMissionNumber++] = newM;
    nextMissions = newArray;
}
void Agency :: executeNextMission(){
    if(nextMissions[0].executeMission()){
        Mission* newArray = new Mission[completedMissionNumber+1];
        for(int i = 0; i< completedMissionNumber; i++) newArray[i] = completedMissions[i];
        delete [] completedMissions;
        Mission newM(nextMissions[0]);
        newArray[completedMissionNumber++] = newM;
        completedMissions = newArray;
    }
    cash += nextMissions[0].calculateProfit(ticket_price);
    Mission* newArray = new Mission[nextMissionNumber-1];
    for(int i = 1; i< nextMissionNumber; i++) newArray[i-1] = nextMissions[i];
    delete [] nextMissions;
    nextMissionNumber--;
    nextMissions = newArray;
}

ostream& operator<<(ostream& os, const Agency& a)
{
    os << "Agency name: "<<a.getName()<<", Total cash: "<<a.getCash() <<", Ticket Price: "<<a.getTicketPrice()<<endl;
    return os;
}

void Agency :: setTicketPrice(int inticket){
    if(inticket > 0) ticket_price = inticket;
    else ticket_price = 0;
}

string Agency ::  getName() const {return name;}
int Agency :: getCash()const {return cash;}
int Agency :: getTicketPrice() const {return ticket_price;}
