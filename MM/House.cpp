#include "House.h"
#include <iostream>

House::House(int type)
{
	this->type=type;
	Suspect killer;
	suspects[0]=killer;

	for(int i=1; i<6; i++){
		Suspect newS(0);
		suspects[i]=newS;}

	Room killed(type);
	rooms[5]=killed;

	for(int i=0; i<5; i++){
		Room newR(i, type);
		rooms[i]=newR;}

	for(int i=6; i<16; i++){
		Room newR(i, type);
		rooms[i]=newR;}
}

void House::displayHouse(int pLocation) const
{
	for (int i=0; i<16; i++)
	{
		if (i%4==0) cout<<endl;
		rooms[i].displayRoom(pLocation);
		if (i==15) cout<<endl;
	}
}

void secretRoom(bool foundSecret)
{
}