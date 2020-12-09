#include "Evidence.h"
#include "Player.h"
#include "Room.h"
#include "Suspect.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

void displayHouse(int location, Room rooms[]);

int main()
{
	time_t t;

	srand((unsigned)time(&t));
	cout<<"What are you?\n1 - Monkey\n2 - Corgi\n3 - Calico\n ";
	int type;
	cin>>type;
	if (type > 3 || type < 1)
	{
		type = abs((type % 3)) + 1;
	}
	Player you(type);

	Suspect suspects[6];
	Suspect killer;
	int killerIndex = rand() % 6;
	suspects[0] = killer;

	for(int i = 1; i < 6; i++)
	{
		if (i == killerIndex)
		{
			suspects[i] = killer;
		}
		else
		{
			Suspect newS(i);
			suspects[i] = newS;
		}
	}

	Room rooms[16];
	Room killed(type);
	rooms[5] = killed;

	for(int i=0; i<5; i++){
		Room newR(i, type, suspects);
		rooms[i]=newR;}

	for(int i=6; i<16; i++){
		Room newR(i, type, suspects);
		rooms[i]=newR;}

	cout<<"HI! You are in a mansion. Someone died here. It was murder."<<endl;
	cout<<"You should determine who it was. Good luck!"<<endl;

	//system("pause");
	//std::cin.get();
	
	cout<<"P is your current location. X means you have searched that room."<<endl;
	displayHouse(you.getLocation(), rooms);

	while(!you.complete){
		cout<<"Enter \"Check\" and a room number to go to and search a room."<<endl;
		cout<<"Enter \"Suspect\" and a number 1 through 6 to show a suspects info."<<endl;
		cout<<"Enter \"Identify\" to identify the murderer."<<endl;
		string in="awesome";
		int sus;
		cin>>in;

		if (in=="Suspect"){
			cin>>sus;
			if (sus<0 || sus>6){
				cout<<"Try again."<<endl;}
			else{
			suspects[sus-1].displaySuspect();
			displayHouse(you.getLocation(), rooms);}}

		if (in=="Identify"){
			cout<<"Who is the murderer? ";
			cin>>in;
			you.identifyKiller(in);}

		if (in=="Check"){
			cin>>sus;
			you.changeLocation(sus, rooms[sus]);
		
			cout<<endl;
			rooms[sus].searched=true;
			//system("pause");
			//std::cin.get();
			displayHouse(you.getLocation(), rooms);}
	}

	return 0;
}

void displayHouse(int plocation, Room rooms[])
{
	for (int i=0; i<16; i++)
	{
		if (i%4==0) cout<<endl;
		rooms[i].displayRoom(plocation);
		if (i==15) cout<<endl;
	}
}
