#ifndef BOOKING_H_
#define BOOKING_H_

#include <string>
#include "Room.h"
#include "Customer.h"
#include "PremiumCustomer.h"
#include <vector>

using namespace std;


class Booking
{
private:
	double price;
	vector <Room> roomAlotted;
	static int number_of_bookings;
	Customer customer;
	bool is_checkedIn;


public:
	Booking();
	Booking(Customer customer, Room room);
	~Booking();
	void set_price(Room& room);
	void set_price(double value);
	double get_price();
	void set_room(Room room);
	vector<Room> get_room();
	void set_customer(Customer customer);
	Customer get_customer();
	void add_room(Room customer_room);
	double priceRate(string room_type);
	void set_checked_in(bool checked_in);
	bool get_checked_in();
	void PrintBookingInfo();

};


#endif 
