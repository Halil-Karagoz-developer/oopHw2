#pragma once
#include "Mission.h"
using namespace std;

class Agency{
    string name;
    int cash;
    int ticket_price;
    Astronaut* crew;
    int crewNumber;
    Mission* completedMissions;
    int completedMissionNumber;
    Mission* nextMissions;
    int nextMissionNumber;
    public:
    //constructors
    Agency();
    Agency(string,int = 0,int = 0);
    Agency(const Agency&);
    ~Agency();
    //other methods

    void addMission(Mission&);
    void executeNextMission();
    friend ostream& operator<<(ostream& os, const Agency& A);

    //setter
    void setTicketPrice(int);

    //getters
    string getName()const;
    int getCash()const ;
    int getTicketPrice() const ;

};