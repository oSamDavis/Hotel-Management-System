#include "Booking.h"

#include <iostream>

using namespace std;

int Booking::number_of_bookings = 0;

Booking::Booking()
{
    roomAlotted;
    price = 0;
    price = get_price();
    is_checkedIn = false;
    customer;

    number_of_bookings++;


}

Booking::Booking(Customer customer, Room room)
{
    set_customer(customer);
    roomAlotted.push_back(room);
    set_price(room);
    price = get_price();
    number_of_bookings++;
    is_checkedIn = false;

    number_of_bookings++;

}

Booking :: ~Booking()
{
    number_of_bookings--;
}

void Booking::set_price(Room& room)
{
    price = customer.get_length() * priceRate(room.get_type());
}
void Booking::set_price(double value)
{
    price = value;

}
double Booking::get_price()
{
    return price;
}

void Booking::set_room(Room room)
{
    roomAlotted.push_back(room);
}

vector<Room> Booking::get_room()
{
    return roomAlotted;
}

void Booking::set_customer(Customer customer)
{
    this->customer = customer;
}

Customer Booking::get_customer()
{
    return customer;
}


void Booking::add_room(Room customer_room)
{
    double temp_Price = price;
    set_price(customer_room);
    price += temp_Price;
    roomAlotted.push_back(customer_room);
}


void Booking::set_checked_in(bool checked_in)
{
    is_checkedIn = checked_in;
}
bool Booking::get_checked_in()
{
    return is_checkedIn;
}

void Booking::PrintBookingInfo()
{
    customer.PrintInfo();
    cout << "\t Room Alocated: ";
    for (int i = 0; i < roomAlotted.size(); i++)
    {
        cout << roomAlotted.at(i).get_description() << endl;
    }

    cout << "\t Total Price of Booking: " << price << endl;
}

double Booking::priceRate(string room_type)
{
    if (room_type == "single" || room_type == "Single")
    {
        return 150;
    }
    else if (room_type == "double" || room_type == "Double")
    {
        return 300;
    }
    else if (room_type == "triple" || room_type == "Triple")
    {
        return 400;
    }
    else if (room_type == "suites" || room_type == "Suites")
    {
        return 800;
    }
    else
    {
        return -1;
    }
}
