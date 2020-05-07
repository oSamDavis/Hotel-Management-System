#include <iostream>
#include "Hotel.h"


using namespace std;



void Reception(Hotel& hotel1);
void Main_Menu(Hotel& hotel1);
int main()
{

	Hotel hotel1("Chika & Sons", 100);
	hotel1.set_description("This is Chika And Sons Hotel. We Offer Hospitality Second To No one. We are the PARENT Hotel!");
	hotel1.set_type("4 STAR LUXURY HOTEL");


	Main_Menu(hotel1);



	hotel1.~Hotel();

	return 0;
}




void Reception(Hotel& hotel1)
{

	int option;
	cout << " Reception Menu " << endl;
	cout << "1. Book a Room." << endl;
	cout << "2. Check-In." << endl;
	cout << "3. Check-Out." << endl;
	cout << "4. Add Booking " << endl;
	cout << "5. Delete Booking " << endl;
	cout << "6. Main Menu." << endl;
	cout << "7. To Exit." << endl;
	cout << "Enter an option:";
	cin >> option;

	switch (option)
	{
	case 1:
	{
		hotel1.book_a_room();
		Main_Menu(hotel1);
		break;
	}

	case 2:
	{
		string firstName, lastName;
		cout << "Enter your Last Name : ";
		cin.ignore();
		getline(cin, lastName);
		cout << "Enter Your First Name: ";
		getline(cin, firstName);

		if (hotel1.check_in(lastName, firstName))
		{
			cout << "Checked in Successfuly! Enjoy Your Stay!" << endl;
		}

		else
		{
			char option;
			cout << "You haven't booked a Room.\n";
			cout << "Would you like to book a Room?\n";
			cout << "Enter Y for yes and N for no";
			cin >> option;
			option = toupper(option);
			if (option == 'Y')
			{
				hotel1.book_a_room();
			}
		}

		break;

	}

	case 3:
	{
		string firstName, lastName;
		cout << "Enter your Last Name : ";
		cin.ignore();
		getline(cin, lastName);
		cout << "Enter Your First Name: ";
		getline(cin, firstName);

		if (hotel1.check_out(lastName, firstName))
		{
			cout << "Checked Out Successfuly! Enjoy Your Stay!" << endl;
		}

		else
		{
			char option;
			cout << "You Have Not Checked In.\n";
			cout << "Would you like to Book A Room?\n";
			cout << "Enter Y for yes and N for no";
			cin >> option;
			option = toupper(option);
			if (option == 'Y')
			{
				hotel1.book_a_room();
			}

			break;
		}


	}

	case 4:
	{
		hotel1.Add_Booking();
		system("pause");
		Main_Menu(hotel1);
		break;
	}

	case 5:
	{
		string firstName, lastName;
		cout << "Enter your Last Name : ";
		cin.ignore();
		getline(cin, lastName);
		cout << "Enter Your First Name: ";
		getline(cin, firstName);

		hotel1.Delete_Booking(lastName, firstName);
		system("pause");
		Main_Menu(hotel1);
		break;
	}


	case 6:
	{
		system("cls");
		Main_Menu(hotel1);
		break;
	}

	case 7:
	{
		exit(0);
		break;

	}

	default:
	{
		system("cls");
		cout << "Wrong Option Entered." << endl;
		Reception(hotel1);

	}


	}
}




void Main_Menu(Hotel& hotel1)
{
	system("cls");
	cout << "           -----------------------------------------" << endl;
	cout << "                           WELCOME TO " << hotel1.get_name() << endl;
	cout << hotel1.get_description() << endl;
	cout << "           -----------------------------------------" << endl;
	cout << "Choose from menu:" << endl;
	cout << endl;
	cout << "1. Reception \n2. View Available Rooms \n3. Get Booking Records \n4. View Hotel Details \n5. Exit" << endl;
	cout << endl << "Enter your choice: ";

	int choice;

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		system("cls");
		Reception(hotel1);
		break;
	}


	case 2:
	{
		hotel1.Print_Available_Rooms();
		system("pause");
		Main_Menu(hotel1);
		break;
	}

	case 3:
	{
		hotel1.PrintAllBookings();
		system("pause");
		Main_Menu(hotel1);
		break;
	}


	case 4:
	{
		hotel1.Print_Hotel_Details();
		system("pause");
		Main_Menu(hotel1);
		break;
	}


	case 5:
		exit(0);
	}
}




