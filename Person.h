#include <iostream>

class Person{
    string name;
    string surname;
    public:
    Person();
    Person(string,string);
    Person(const Person&);
};

class Passanger : public Person{
    int cash;
    bool ticket;
    
};