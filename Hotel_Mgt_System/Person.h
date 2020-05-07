#ifndef PERSON_H
#define PERSON_H
#include "Address.h"
#include<string>

using namespace std;

class Person
{

protected:
    string firstName;
    string lastName;
    Address person_address;

public:
    Person();
    Person(string firstName, string lastName);
    string getFirstName();
    string getLastName();
    void setFirstName(string firstName);
    void setLastName(string lastName);
    Address get_address();
    void set_address();
    virtual void PrintInfo() const = 0;


};
#endif