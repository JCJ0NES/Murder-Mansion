#ifndef HOUSE_H
#define HOUSE_H
#include "Suspect.h"
#include "Room.h"

using namespace std;

class House
{
public:
	House();
	House(int type);
	void displayHouse(int pLocation) const;
	void secretRoom(bool foundSecret);
	Room rooms[16];
	Suspect suspects[6];
	int type;
};
#endif