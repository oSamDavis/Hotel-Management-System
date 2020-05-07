#ifndef HOTEL_H_
#define HOTEL_H_

#include "Address.h"
#include "Room.h"
#include "Booking.h"
#include "Customer.h"
#include "PremiumCustomer.h"
#include <string>
#include <vector>

using namespace std;

class Hotel
{
private:
	int hotel_id;
	string hotel_name;
	string hotel_type;
	string hotel_description;
	Address hotel_address;
	int number_of_guest;
	int hotel_capacity;
	static int number_of_hotels;
	vector<Booking*> booking_records;
	Room* hotel_rooms;
	void set_hotel_rooms(Room* hotel_rooms);





public:
	Hotel();
	Hotel(string hotel_name, string hotel_type, string hotel_description, int hotel_capacity);
	Hotel(string hotel_name, int hotel_capacity);
	Hotel(const Hotel& hotel);
	~Hotel();
	//	void set_id(int hotel_id);
	int get_id() const;
	void set_name(string hotel_name);
	string get_name() const;
	void set_type(string hotel_type);
	string get_type() const;
	void set_description(string hotel_description);
	string get_description() const;
	void set_address();
	Address get_address() const;
	void set_capacity(int hotel_capacity);
	int get_capacity() const;
	Room* get_hotel_rooms() const;
	void Add_Booking();
	void Delete_Booking(string customer_lastName, string customer_firstName);
	void PrintAllBookings() const;
	void Print_Available_Rooms() const;
	void Print_Hotel_Details() const;
	static int get_Number_of_hotels();
	void book_a_room();
	bool check_in(string customer_lastName, string customer_firstname);
	bool check_out(string customer_lastName, string customer_firstName);
	friend 	void assign_a_room(Hotel& hotel, Room& customer_room_choice);



};


#endif // !HOTEL_h_
