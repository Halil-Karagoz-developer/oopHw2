#include <iostream>
#include <string>

#include "Person.h"

using namespace std;



Person :: Person(){
    name = " ";
    surname = " ";
}

Person :: Person(string inname, string insurname) : name(inname),surname(insurname){}

Person :: Person(const Person& p) : name(p.name), surname(p.surname){}

string Person :: getName() {return name;}
string Person :: getSurname() {return surname;}


Passenger :: Passenger() : Person() , cash(0),ticket(true){}

Passenger :: Passenger(string inname,string insurname,int incash, bool inticket) : Person(inname,insurname){
    if(incash >= 0)
        cash = incash;

    else{
        cash = 0;
        cout <<"error"<<endl; // it will change
    }
}

Passenger :: Passenger(Passenger& p) : Person(p),cash(p.cash),ticket(p.ticket){}

bool Passenger ::  buyTicket(int p){
    if(cash >= p){
        ticket = true;
        return true;
    }
    ticket = false;
    return false;
    
}
bool Passenger :: getThicket(){return ticket;}

Astronaut :: Astronaut() : Person(), numMissions(0) {}

Astronaut :: Astronaut(string inname, string insurname, int num) : Person(inname,insurname){
    if(num < 0){
        cout <<"Number of missions that astronaut completed can't be negative. It is set to 0."<<endl;
        numMissions = 0;
    }
    else numMissions = num;
}

Astronaut :: Astronaut(const Astronaut& a) : Person(a),numMissions(a.numMissions){}

void Astronaut :: completeFlight(){numMissions++;}
void Astronaut :: writeCompletedMessage(){
    cout << "Astronaut " <<this->getName()<<" "<< this->getSurname()<<" successfully completed "<<numMissions<< " missions."<<endl;
}