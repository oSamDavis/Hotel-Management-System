#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person() {
    firstName = "";
    lastName = "";
}

Person::Person(string firstName, string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
    set_address();

}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

Address Person::get_address() {
    return person_address;
}

void Person::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Person::setLastName(string lastName) {
    this->lastName = lastName;
}

void Person::set_address()
{
    person_address.GetAddressData();
}