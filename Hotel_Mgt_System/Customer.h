#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Person.h"

using namespace std;

class Customer :public Person {
protected:
    string phoneNo;
    string inDate;
    int length_of_stay;
    string email_address;
    static int number_of_customers;


public:
    Customer();
    Customer(string firstName, string lastName, string phoneNo, string inDate, int length_of_stay, string email_address);
    ~Customer();
    void setPhone(string phoneNo);
    string getPhone() const;
    void setInDate(string inDate);
    string getInDate() const;
    void set_length(int length_of_stay);
    int get_length() const;
    void setEmailAddress(string email_address);
    string getEmailAddress() const;
    static int get_Number_of_Customers();
    void PrintInfo() const override;
    virtual void Get_CustomerData();

};

#endif