// @Author= Halil Faruk Karagöz 
// No : 150180014
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    string surname;
    public:
    Person();
    Person(string,string);
    Person(const Person&);
    //getters
    string getName();
    string getSurname();
};

class Passenger : public Person{
    int cash;
    bool ticket;
    public:
    bool buyTicket(int);
    Passenger();
    Passenger(string,string = " ",int = 0,bool = false);
    Passenger(Passenger&);
    //getters
    bool getThicket();
};

class Astronaut : public Person{
    int numMissions;
    public:
    Astronaut();
    Astronaut(string, string = " ", int = 0);
    Astronaut(const Astronaut&);
    void completeFlight();
    void writeCompletedMessage();
};