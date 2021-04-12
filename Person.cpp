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