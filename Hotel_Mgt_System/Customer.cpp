#include "Customer.h"

#include <iostream>
using namespace std;

int Customer::number_of_customers = 0;

Customer::Customer() : Person()
{
	length_of_stay = 0;
	number_of_customers++;

}

Customer::Customer(string firstName, string lastName, string phoneNo, string inDate, int length_of_stay, string email_address) : Person(firstName, lastName)
{
	setPhone(phoneNo);
	setInDate(inDate);
	set_length(length_of_stay);
	setEmailAddress(email_address);

	number_of_customers++;

}

Customer :: ~Customer()
{
	number_of_customers--;

}

void Customer::setPhone(string phoneNo)
{
	this->phoneNo = phoneNo;

}
string Customer::getPhone() const
{
	return phoneNo;
}
void Customer::setInDate(string inDate)
{
	this->inDate = inDate;
}

string Customer::getInDate() const
{
	return inDate;
}

void Customer::set_length(int length_of_stay)
{
	this->length_of_stay = length_of_stay;

}
int Customer::get_length() const
{
	return length_of_stay;
}
void Customer::setEmailAddress(string email_address)
{
	this->email_address = email_address;
}
string Customer::getEmailAddress() const
{
	return email_address;
}

int Customer::get_Number_of_Customers()
{
	return number_of_customers;
}

void Customer::PrintInfo() const
{
	cout << "Customer Info:" << endl;
	cout << "\t Customer Name: " << firstName << " " << lastName << endl;
	cout << "\t Customer Phone Number: " << phoneNo << endl;
	cout << "\t Customer Email Address: " << email_address << endl;

}

void Customer::Get_CustomerData()
{
	string first_name;
	string last_name;
	string phoneNo;
	string inDate;
	int length_of_stay;
	string email_address;

	cout << "Enter your First Name: ";
	cin.ignore();
	getline(cin, first_name);
	cout << "Enter your Last Name: ";
	getline(cin, last_name);
	cout << "Enter your Phone Number: ";
	getline(cin, phoneNo);
	cout << "Enter Date you wish to Arrive: ";
	getline(cin, inDate);
	cout << "Enter The Length Of Your Stay: ";
	cin >> length_of_stay;
	cout << "Enter your Email Address: ";
	cin.ignore();
	getline(cin, email_address);

	setFirstName(first_name);
	setLastName(last_name);
	setPhone(phoneNo);
	setInDate(inDate);
	set_length(length_of_stay);
	setEmailAddress(email_address);
}