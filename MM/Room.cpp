#include "Room.h"
#include <iostream>

Room::Room()
{
}

Room::Room(int type)
{
	this->type = type;

	if (type == 1)
	{
		milkBones = 0;
		catNip = 0;
		bananas = rand() % 11;
	}

	if (type == 2)
	{
		milkBones = rand() % 11;
		catNip = 0;
		bananas = 0;
	}

	if (type == 3)
	{
		milkBones = 0;
		catNip = rand() % 11;
		bananas = 0;
	}

	hasEvidence = rand() % 2;

	size = 1 + rand() % 3;
	
	this->location = 5;

	Evidence evidence;

	this->evidence = evidence;
	searched = false;
}

Room::Room(int location, int type, Suspect suspects[])
{
	if (type == 1)
	{
		milkBones = 0;
		catNip = 0;
		bananas = rand() % 11;
	}

	if (type == 2)
	{
		milkBones = rand() % 11;
		catNip = 0;
		bananas = 0;
	}

	if (type == 3)
	{
		milkBones = 0;
		catNip = rand() % 11;
		bananas = 0;
	}

	hasEvidence = rand() % 2;

	size = 1 + rand() % 3;

	this->location = location;

	Evidence evidence(location, suspects);

	this->evidence = evidence;
	searched = false;
}

void Room::displayRoom(int pLocation) const
{
	if (location < 10)
	{
		cout << "[" << location << " ";
	}
	else
	{
		cout << "[" << location;
	}
	if (location == pLocation)
	{
		cout << " P";
	}
	else
	{
		cout << "  ";
	}
	if (searched)
	{
		cout << "X";
	}
	else if (!searched)
	{
		cout << " ";
	}
	cout << "]  ";
}

int Room::getLocation() const
{
	return location;
}

void Room::search()
{
	searched = true;
	cout << endl;

	if (location == 5)
	{
		cout << "Gross. The body is still in here." << endl;
	}

	switch (size) {
	case 1:
		cout << "This room is small." << endl;
		break;
	case 2:
		cout << "An average sized room." << endl;
		break;
	case 3:
		cout << "This room is large." << endl;
		break;
	default:
		break;
	}

	switch (type)
	{
	case 1:
		cout << "Sweet! " << bananas << " bananas!" << endl;
		break;
	case 2:
		cout << "Sweet! " << milkBones << " Milk Bones!" << endl;
		break;
	case 3:
		cout << "Sweet! " << catNip << " Cat Nip!" << endl;
		break;
	default:
		break;
	}
	
	cout << "There is evidence!" << endl;

	evidence.displayEvidence();
}