#include "Evidence.h"
#include "Player.h"
#include "Room.h"
#include "Suspect.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

const int HOUSE_I = 4;
const int HOUSE_J = 4;

template <size_t rows, size_t cols>
void displayHouse(int plocation, Room(&rooms)[rows][cols]);

int main()
{
	time_t t;
	int type; //Determines whether player is a monkey, corgi, or calico

	srand((unsigned)time(&t));
	cout << "What are you?\n1 - Monkey\n2 - Corgi\n3 - Calico\n ";
	cin >> type;

	if (type > 3 || type < 1)
	{
		type = abs((type % 3)) + 1;
		cout << "That wasn't a valid choice so I have made you a Corgi.\n" <<
			"If you do not follow directions, you will lose the privilege of choice.\n\n";
	}

	//Instantiate various parts of game
	Player you(type);
	Suspect suspects[6];
	Suspect killer;
	int killerIndex = rand() % 6;

	//Set Suspects
	for(int i = 0; i < 6; i++)
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

	//Instantiate rooms of house
	Room rooms[HOUSE_I][HOUSE_J];
	Room killed(type);
	int bodyLocI = rand() % HOUSE_I; // Represents the coordinates of the deceased victim
	int bodyLocJ = rand() % HOUSE_J;

	//Set rooms of house
	for (int i = 0; i < HOUSE_I; i++)
	{
		for (int j = 0; j < HOUSE_J; j++)
		{
			if (i == bodyLocI && j == bodyLocJ)
			{
				rooms[i][j] = killed;
			}
			else 
			{
				Room newR(i * HOUSE_I + j, type, suspects);
				rooms[i][j] = newR;
			}
		}
	}

	cout << "HI! You are in a mansion. Someone died here. It was murder." << endl;
	cout << "You should determine who it was. Good luck!" << endl;
	cout << "P is your current location. X means you have searched that room." << endl;
	displayHouse(you.getLocation(), rooms);

	while(!you.complete){
		cout << "Enter \"Check\" and a room number to go to and search a room." << endl;
		cout << "Enter \"Suspect\" and a number 1 through 6 to show a suspects info." << endl;
		cout << "Enter \"Identify\" to identify the murderer." << endl;
		string in = "awesome";
		int sus;
		cin >> in;

		for (int i = 0; i < in.length(); i++)
		{
			in[i] = tolower(in[i]);
		}

		if (in == "suspect"){
			cin >> sus;
			if (sus<0 || sus>6){
				cout << "Try again." << endl;}
			else{
			suspects[sus-1].displaySuspect();
			displayHouse(you.getLocation(), rooms);}}

		if (in == "identify"){
			cout << "Who is the murderer? ";
			cin >> in;
			you.identifyKiller(in);}

		if (in == "check"){
			cin >> sus;
			you.changeLocation(sus, rooms[sus / HOUSE_I][sus % HOUSE_J]);
		
			cout << endl;
			rooms[sus / HOUSE_I][sus % HOUSE_J].searched=true;
			displayHouse(you.getLocation(), rooms);}
	}

	return 0;
}

template <size_t rows, size_t cols>
void displayHouse(int plocation, Room(&rooms)[rows][cols])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			rooms[i][j].displayRoom(plocation);
		}
		cout << endl;
	}
	cout << endl;
}