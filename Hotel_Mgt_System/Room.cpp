#include "Room.h"
#include <iostream>
using namespace std;

int Room::number_of_rooms = 0;

Room::Room()
{
	room_number = number_of_rooms + 1;
	room_type = "";
	room_description = "";
	is_available = true;

	number_of_rooms++;
}

Room::Room(string room_type, string room_description)
{
	set_number(room_number);
	set_type(room_type);
	set_availability(is_available);
	is_available = true;

	number_of_rooms++;
}

Room :: ~Room()
{
	number_of_rooms--;
}
void Room::set_number(int room_number)
{
	this->room_number = room_number;

}

int Room::get_number() const
{
	return room_number;
}

void Room::set_type(string room_type)
{
	this->room_type = room_type;
}
string Room::get_type() const
{
	return room_type;
}
void Room::set_description(string room_description)
{
	this->room_description = room_description;

}
string Room::get_description() const
{
	return room_description;
}
void Room::set_availability(bool is_available)
{
	this->is_available = is_available;
}
bool Room::get_availability() const
{
	return is_available;
}


void Room::printInfo() const
{
	cout << "Room Info:" << endl;
	cout << "\t Room Number: " << room_number << endl;
	cout << "\t Room Type: " << room_type << endl;
	cout << "\t Room Description: " << room_description << endl;
	cout << "\t Room Availability: " << (is_available == true ? "Available" : "Not Available") << endl;

}

int Room::get_Number_of_rooms()
{
	return number_of_rooms;
}
