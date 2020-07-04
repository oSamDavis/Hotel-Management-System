#ifndef PREMIUMCUSTOMER_H_
#define PREMIUMCUSTOMER_H_

#include "Customer.h"

#include <string>
using namespace std;

class PremiumCustomer : public Customer
{
private:
	string member_username;
	static double member_rate;
	static int number_of_Premium_customers;
	double member_points;

public:
	PremiumCustomer();
	PremiumCustomer(string member_usernmae);
	~PremiumCustomer();
	void set_memberUsername(string member_username);
	string get_memberUsername() const;
	void set_memberPoints(double member_points);
	double get_memberPoints() const;
	void operator++();
	void PrintInfo() const override;
	static void set_member_rate(double new_rate);
	static double get_member_rate();
	void Get_CustomerData() override;


};


#endif