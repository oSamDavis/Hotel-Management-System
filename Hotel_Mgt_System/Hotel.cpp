#include "Hotel.h"
#include "Address.h"

#include <iostream>
using namespace std;

#include <vector>



int Hotel::number_of_hotels = 0;

Hotel::Hotel()
{
	hotel_id = number_of_hotels + 1;
	hotel_name = "";
	hotel_type = "";
	hotel_description = "";
	hotel_address;
	int number_of_guest = 0;
	int hotel_capacity = 0;

	hotel_rooms = new Room[hotel_capacity];
	set_hotel_rooms(hotel_rooms);

	number_of_hotels++;


}

Hotel::Hotel(string hotel_name, string hotel_type, string hotel_description, int hotel_capacity)
{
	hotel_id = number_of_hotels + 1;
	set_name(hotel_name);
	set_type(hotel_type);
	set_description(hotel_description);
	set_capacity(hotel_capacity);

	hotel_rooms = new Room[hotel_capacity];
	set_hotel_rooms(hotel_rooms);

	set_address();

	number_of_hotels++;

}
Hotel::Hotel(string hotel_name, int hotel_capacity)
{
	hotel_id = number_of_hotels + 1;
	set_name(hotel_name);
	set_capacity(hotel_capacity);

	hotel_rooms = new Room[hotel_capacity];
	set_hotel_rooms(hotel_rooms);

	set_address();

	number_of_hotels++;

}
Hotel::Hotel(const Hotel& hotel)
{
	hotel_id = number_of_hotels + 1;
	set_name(hotel.hotel_name);
	set_type(hotel.hotel_type);
	set_description(hotel.hotel_description);
	set_capacity(hotel.hotel_capacity);

	hotel_rooms = new Room[hotel_capacity];
	set_hotel_rooms(hotel_rooms);

	set_address();

	number_of_hotels++;

}

Hotel :: ~Hotel()
{
	delete[] hotel_rooms;
	if (!booking_records.empty())
	{
		for (int i = 0; i < booking_records.size(); i++)
		{
			delete booking_records.at(i);
		}
	}
	number_of_hotels--;

}


int Hotel::get_id() const
{
	return hotel_id;
}

void Hotel::set_name(string hotel_name)
{
	this->hotel_name = hotel_name;
}

string Hotel::get_name() const
{
	return hotel_name;
}

void Hotel::set_type(string hotel_type)
{
	this->hotel_type = hotel_type;

}
string Hotel::get_type() const
{
	return hotel_type;
}
void Hotel::set_description(string hotel_description)
{
	this->hotel_description = hotel_description;
}

string Hotel::get_description() const
{
	return hotel_description;
}

void Hotel::set_address()
{
	hotel_address.GetAddressData();

}
Address Hotel::get_address() const
{
	return hotel_address;
}
void Hotel::set_capacity(int hotel_capacity)
{
	this->hotel_capacity = hotel_capacity;
}
int Hotel::get_capacity() const
{
	return hotel_capacity;
}


int Hotel::get_Number_of_hotels()
{
	return number_of_hotels;
}

Room* Hotel::get_hotel_rooms() const
{
	return hotel_rooms;
}





void Hotel::set_hotel_rooms(Room* hotel_rooms)
{
	int types_of_rooms = 4;
	int number_of_each_type = hotel_capacity / types_of_rooms;

	for (int i = 0; i < number_of_each_type; i++)
	{
		hotel_rooms[i].set_type("Single");
		hotel_rooms[i].set_description("One bed \n Max number of guests = 2");
		hotel_rooms[i].set_number(i + 1);
	}

	for (int i = number_of_each_type; i < number_of_each_type * 2; i++)
	{
		hotel_rooms[i].set_type("Double");
		hotel_rooms[i].set_description("Two beds\n Max number of guests = 4");
		hotel_rooms[i].set_number(i + 1);
	}

	for (int i = number_of_each_type * 2; i < number_of_each_type * 3; i++)
	{
		hotel_rooms[i].set_type("Triple");
		hotel_rooms[i].set_description("Three beds\n Max number of guests = 6");
		hotel_rooms[i].set_number(i + 1);
	}

	for (int i = number_of_each_type * 3; i < hotel_capacity; i++)
	{
		hotel_rooms[i].set_type("Suites");
		hotel_rooms[i].set_description("Three beds and a Living Room\n Max number of guests = 6");
		hotel_rooms[i].set_number(i + 1);
	}

}



// Book A Room Functiom
void Hotel::book_a_room()
{
	int option;
	system("cls");
	cout << "Book a Room " << endl;
	cout << "1. For Premium Customers: " << endl;
	cout << "2. For Regular Customer: " << endl;
	cout << "3. Exit" << endl;
	cout << "Enter option: ";
	cin >> option;

	switch (option)
	{
	case 1:
	{
		PremiumCustomer premium_customer;
		Room customer_room_choice;

		premium_customer.Get_CustomerData();
		premium_customer.set_address();


		assign_a_room(*this, customer_room_choice);

		Booking* premium_booking = new Booking(premium_customer, customer_room_choice);
		booking_records.push_back(premium_booking);
		char book_extra = 'N';
		cout << "Would you Like to Book Another Room ";
		cout << "Enter Y for yes: ";
		cin >> book_extra;
		while (book_extra == 'Y' || book_extra == 'y')
		{
			premium_booking++; //increase  points of member;
			assign_a_room(*this, customer_room_choice);
			premium_booking->add_room(customer_room_choice);
			booking_records.push_back(premium_booking);
			cout << "Would you Like to Book Another Room ";
			cout << "Enter Y for yes: ";
			cin >> book_extra;


		}

		double new_price = premium_booking->get_price() - (PremiumCustomer::get_member_rate() * premium_customer.get_memberPoints());
		premium_booking->set_price(new_price);


		break;

	}
	case 2:
	{
		Customer regular_customer;
		Room customer_room_choice;

		regular_customer.Get_CustomerData();
		regular_customer.set_address();

		assign_a_room(*this, customer_room_choice);

		Booking* regular_booking = new Booking(regular_customer, customer_room_choice);
		booking_records.push_back(regular_booking);
		char book_extra = 'N';
		cout << "Would you Like to Book Another Room ";
		cout << "Enter Y for yes: ";
		cin >> book_extra;
		while (book_extra == 'Y' || book_extra == 'y')
		{
			assign_a_room(*this, customer_room_choice);
			regular_booking->add_room(customer_room_choice);
			booking_records.push_back(regular_booking);
			cout << "Would you Like to Book Another Room ";
			cout << "Enter Y for yes: ";
			cin >> book_extra;

		}
		break;

	}
	case 3:
	{
		exit(0);
	}


	default:
	{	system("cls");
	cout << "Wrong Option" << endl;
	book_a_room();
	break;

	}



	} // Switch



}



//Check In
bool Hotel::check_in(string customer_lastName, string customer_firstName)
{

	for (int i = 0; i < booking_records.size(); i++)
	{
		if (booking_records.at(i)->get_customer().getLastName() == customer_lastName && booking_records.at(i)->get_customer().getFirstName() == customer_firstName)
		{
			booking_records.at(i)->set_checked_in(true);
			return true;

		}

	}

	return false;

}

//Check_Out
bool Hotel::check_out(string customer_lastName, string customer_firstName)
{
	for (int i = 0; i < booking_records.size(); i++)
	{

		if (booking_records.at(i)->get_checked_in())
		{
			booking_records.at(i)->set_checked_in(false);
			for (int i = 0; i < booking_records.at(i)->get_room().size(); i++)
			{
				booking_records.at(i)->get_room().at(i).set_availability(true);
			}
			return true;

		}

	}

	return false;
}








void assign_a_room(Hotel& hotel, Room& customer_room_choice)
{
	system("cls");
	int book_option;
	cout << "Would you like to Book Room By Type or By Number." << endl;
	cout << "1. By Type" << endl;
	cout << "2. By Number" << endl;
	cin >> book_option;

	if (book_option == 1)
	{
		string room_type;
		std::cout << "Room Types : \n Single \n Double \n Triple \n Suites " << endl;
		cout << "Enter Room Type: ";
		cin.ignore();
		getline(cin, room_type);

		for (int i = 0; i < hotel.hotel_capacity; i++)
		{
			if (room_type == hotel.hotel_rooms[i].get_type() && hotel.hotel_rooms[i].get_availability())
			{
				customer_room_choice = hotel.hotel_rooms[i];
				hotel.hotel_rooms[i].set_availability(false);
				cout << "Room Booked Successfully! " << endl;
				cout << customer_room_choice.get_description() << endl;
				break;

			}

			if (i == hotel.hotel_capacity - 1)
			{
				cout << room_type << "Room is not Available" << endl;
				break;
			}

		}

	}

	else if (book_option == 2)
	{
		int room_number;
		cout << "Room Numbers From 1 to " << hotel.hotel_capacity << endl;
		cout << "Rooms 1 to " << hotel.hotel_capacity / 4 << " Single Rooms." << endl;
		cout << "Rooms " << hotel.hotel_capacity / 4 << " to " << (2 * hotel.hotel_capacity) / 4 << " Double Rooms." << endl;
		cout << "Rooms " << (2 * hotel.hotel_capacity) / 4 << " to " << (3 * hotel.hotel_capacity) / 4 << " Triple Rooms." << endl;
		cout << "Rooms " << (3 * hotel.hotel_capacity) / 4 << " to " << hotel.hotel_capacity << "  Suites." << endl;

		cin >> room_number;
		if (room_number >= 1 && room_number <= hotel.hotel_capacity)
		{
			for (int i = 0; i < hotel.hotel_capacity; i++)
			{
				if (room_number == hotel.hotel_rooms[i].get_number() && hotel.hotel_rooms[i].get_availability())
				{
					customer_room_choice = hotel.hotel_rooms[i];
					hotel.hotel_rooms[i].set_availability(false);
					cout << "Room Booked Successfully! " << endl;
					cout << customer_room_choice.get_description() << endl;
					break;
				}

				if (i == hotel.hotel_capacity - 1)
				{
					cout << " Room " << room_number << " is not Available " << endl;
					break;
				}
			}

		}
	}



}


void Hotel::PrintAllBookings() const
{

	if (booking_records.size() == 0)
	{
		cout << "No Available Booking Records To Print " << endl;
	}
	for (int i = 0; i < booking_records.size(); i++)
	{
		booking_records.at(i)->PrintBookingInfo();
	}
}


//ADD BOOKING
void Hotel::Add_Booking()
{
	(*this).book_a_room();
	cout << "Booking Added Successfully" << endl;
}

//DELETE BOOKING
void Hotel::Delete_Booking(string customer_lastName, string customer_firstName)
{
	if (booking_records.empty())
		cout << "No Booking Record to Delete" << endl;

	else
	{
		for (int i = 0; i < booking_records.size(); i++)
		{
			if (booking_records.at(i)->get_customer().getLastName() == customer_lastName && booking_records.at(i)->get_customer().getFirstName() == customer_firstName)
			{
				for (int j = 0; j < booking_records.at(i)->get_room().size(); j++)
				{
					booking_records.at(i)->get_room().at(j).set_availability(true);
				}
				booking_records.erase(booking_records.begin(), booking_records.begin() + i);
				cout << "Booking Deleted Successfully" << endl;

			}

		}

		cout << "Booking Record Not Found. " << endl;

	}





}

void Hotel::Print_Available_Rooms() const
{
	cout << "Available Rooms Are: " << endl;
	for (int i = 0; i < hotel_capacity; i++)
	{
		if (hotel_rooms[i].get_availability())
			cout << "\tRoom Number " << hotel_rooms[i].get_number() << " Room Type - " << hotel_rooms[i].get_type() << endl;
	}
}

void Hotel::Print_Hotel_Details() const
{
	cout << "Hotel Details " << endl;
	cout << "\t Hotel Name: " << hotel_name << endl;
	cout << "\t Hotel Description: " << hotel_description << endl;
	cout << "\t Hotel Type: " << hotel_type << endl;
	hotel_address.printAddress();

}
