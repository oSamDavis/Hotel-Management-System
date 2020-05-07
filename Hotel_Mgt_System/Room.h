#ifndef ROOM_H_
#define ROOM_H_

#include <string>
using namespace std;
class Room
{
private:
	int room_number;
	string room_type;
	string room_description;
	bool is_available;
	static int number_of_rooms;

public:
	Room();
	Room(string room_type, string room_description);
	~Room();
	void set_number(int room_number);
	int get_number() const;
	void set_type(string room_type);
	string get_type() const;
	void set_description(string room_description);
	string get_description() const;
	void set_availability(bool is_available);
	bool get_availability() const;
	void printInfo() const;
	static int get_Number_of_rooms();

};



#endif // !ROOM_H_
