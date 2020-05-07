#include "PremiumCustomer.h"

#include <iostream>
using namespace std;

int PremiumCustomer::number_of_Premium_customers = 0;

double PremiumCustomer::member_rate = 12.5;

PremiumCustomer::PremiumCustomer() : Customer()
{
	member_username = "";
	member_points = 1;

}
PremiumCustomer::PremiumCustomer(string member_username)
{
	set_memberUsername(member_username);

	number_of_Premium_customers++;

}

PremiumCustomer::~PremiumCustomer()
{
	number_of_Premium_customers--;
}

void PremiumCustomer::set_memberUsername(string member_username)
{
	this->member_username = member_username;

	number_of_Premium_customers++;

}
string PremiumCustomer::get_memberUsername() const
{
	return member_username;
}

void PremiumCustomer::set_memberPoints(double member_points)
{
	this->member_points = member_points;
}

double PremiumCustomer::get_memberPoints() const
{
	return member_points;
}

void PremiumCustomer :: operator++()
{
	++member_points;
}

void PremiumCustomer::set_member_rate(double new_rate)
{
	member_rate = new_rate;
}
double PremiumCustomer::get_member_rate()
{
	return member_rate;
}

void PremiumCustomer::PrintInfo() const
{

	cout << "Premium Customer Info:" << endl;
	cout << "\t Premium Customer Name: " << firstName << " " << lastName << endl;
	cout << "\t Premium Customer Phone Number: " << phoneNo << endl;
	cout << "\t Premium Customer Email Address: " << email_address << endl;
	cout << "\t Premium Customer Username: " << member_username << endl;
	cout << "\t Membership points: " << member_points << endl;

}

void PremiumCustomer::Get_CustomerData()
{
	string user_name;
	Customer::Get_CustomerData();
	cout << "Enter your Member Username: ";
	getline(cin, user_name);
	set_memberUsername(user_name);


}