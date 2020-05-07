#include "Address.h"
#include <iostream>

using namespace std;

Address::Address()
{
	address_number = 0;
	street_name = "";
	city = "";
	state = "";
	zipcode = 0;
}

Address::Address(int address_number, string street_name, string city, string state, int zipcode)
{
	set_number(address_number);
	set_streetName(street_name);
	set_city(city);
	set_state(state);
	set_zipcode(zipcode);

}

Address::Address(const Address& address)
{
	set_number(address.address_number);
	set_streetName(address.street_name);
	set_city(address.city);
	set_state(address.state);
	set_zipcode(address.zipcode);
}

void Address::set_number(int address_number)
{
	this->address_number = address_number;
}
int Address::get_number() const
{
	return address_number;
}

void Address::set_streetName(string street_name)
{
	this->street_name = street_name;

}
string Address::get_streetName() const
{
	return street_name;
}
void Address::set_city(string city)
{
	this->city = city;

}
string Address::get_city()
{
	return city;
}

void Address::set_state(string state)
{
	this->state = state;
}
string Address::get_state() const
{
	return state;
}
void Address::set_zipcode(int zipcode)
{
	this->zipcode = zipcode;
}
int Address::get_zipcode() const
{
	return zipcode;
}


void Address::printAddress() const
{
	cout << "Hotel Address : " << endl;
	cout << "\tStreet Name and Number: " << address_number << " " << street_name << endl;
	cout << "\tCity: " << city << endl;
	cout << "\tState: " << state << endl;
	cout << "\tZipcode: " << zipcode << endl;

}

void Address::GetAddressData()
{
	int address_number;
	string street_name;
	string city;
	string state;
	int zipcode;

	cout << "Enter Address Number: ";
	cin >> address_number;


	cout << "Enter Street Name: ";
	cin.ignore();
	getline(cin, street_name);


	cout << "Enter City: ";
	getline(cin, city);


	cout << "Enter State: ";
	getline(cin, state);


	cout << "Enter Zipcode: ";
	cin >> zipcode;

	set_number(address_number);
	set_streetName(street_name);
	set_city(city);
	set_state(state);
	set_zipcode(zipcode);
}