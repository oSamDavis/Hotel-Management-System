#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>
using namespace std;

class Address
{
private:
	int address_number;
	string street_name;
	string city;
	string state;
	int zipcode;

public:
	Address();
	Address(int address_number, string street_name, string city, string state, int zipcode);
	Address(const Address& address);
	void set_number(int address_number);
	int get_number() const;
	void set_streetName(string street_name);
	string get_streetName() const;
	void set_city(string city);
	string get_city();
	void set_state(string state);
	string get_state() const;
	void set_zipcode(int zipcode);
	int get_zipcode() const;
	void printAddress() const;
	void GetAddressData();

};








#endif // !ADDRESS_h_
