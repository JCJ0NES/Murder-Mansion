#ifndef ROOM_H
#define ROOM_H
#include "Evidence.h"
#include <ctime>
#include <cstdlib>
using namespace std;

class Room
{
private:
	int bananas;
	int catNip;
	bool hasEvidence;
	int location;
	int milkBones;
	int size;
	int type;
public:
	Room();
	Room(int type);
	Room(int location, int type, Suspect suspects[]);
	void displayRoom(int pLocation) const;
	int getLocation()  const;
	void search();

	Evidence evidence;
	bool searched;
};
#endif