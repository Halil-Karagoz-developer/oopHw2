#include "Mission.h"
#include <iostream>
using namespace std;

Mission :: Mission () : name("AA-00"){
    cost = 0;
    missionNumber= 0;
    faultProbability = 0;
    completed = false;
    PassengersNumber = 0;
    crewNumber = 0;
}

Mission :: Mission(string inname,int incost,int infaultProbability,int inmissionNumber,bool incompleted)
: cost(incost),faultProbability(infaultProbability),missionNumber(inmissionNumber),completed(incompleted)
{
    crewNumber = 0;
    PassengersNumber = 0;
    bool string_is_valid= true;
    if(inname.length() != 5) string_is_valid = false;
    if(inname[0] <64 || inname[0] > 90) string_is_valid = false;
    if(inname[1] <64 || inname[1] > 90) string_is_valid = false;
    if(inname[2] != 45) string_is_valid = false;
    if(inname[3] <47 || inname[3] > 57) string_is_valid = false;
    if(inname[4] <47 || inname[4] > 57) string_is_valid = false;
    if(string_is_valid)
        name = inname;
    else{
        cout <<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
        name = "AA-00";
    }
    
}

Mission :: Mission(const Mission& m): 
name(m.name),faultProbability(m.faultProbability),cost(m.cost),missionNumber(m.missionNumber),completed(m.completed){
    crewNumber = m.crewNumber;
    PassengersNumber = m.PassengersNumber;
    Passengers = new Passenger[m.PassengersNumber];
    crew = new Astronaut[m.crewNumber];
    for(int i = 0; i< PassengersNumber; i++){
        Passengers[i] = (m.Passengers)[i];
    }
    for(int i = 0; i< crewNumber; i++){
        crew[i] = (m.crew)[i];
    }
}

Mission :: ~Mission(){
    delete [] Passengers;
    delete [] crew;
}

void Mission :: operator+=(Passenger* p){
    if(p->getThicket())
    {   
        Passenger* newP = new Passenger [PassengersNumber+1] ;
        for(int i = 0; i< PassengersNumber; i++){
            newP[i] = Passengers[i];
        }
        newP[PassengersNumber++] = *p;
        delete [] Passengers;
        Passengers = newP;
    }
    else{
        cout << "Passenger "<<p->getName()<<" "<< p->getSurname()<< "does not have a valid ticket!"<<endl;
    }

}

void Mission ::  operator+=(Astronaut* a){
    Astronaut* newA = new Astronaut [crewNumber+1] ;
    for(int i = 0; i< crewNumber; i++){
        newA[i] = crew[i];
    }
    newA[crewNumber++] = *a;
    delete [] crew;
    crew = newA;
    
}
bool Mission :: executeMission(){
    int random = std::rand();
    if(random > faultProbability){
        completed = true;
        cout << "MISSION "<<  name << " SUCCESSFUL!"<<endl;
        for(int i = 0; i< crewNumber; i++){
            crew[i].completeFlight();
            crew[i].writeCompletedMessage();
        }
        return true;
    }
    else {
        cout <<"MISSION " << name<< " FAILED!"<<endl;
        return false;
    }
}

int Mission :: calculateProfit(int price){
    if(completed){
        return PassengersNumber*price-cost;
    }
    else return cost;
}

string Mission :: getName()const {return name;}

  
void Mission ::  setName(string inname) {name.assign(inname);}
