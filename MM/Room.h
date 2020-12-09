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
	int milkBones;
	int catNip;
	bool hasEvidence;
	int size;
	int location;
	int type;
public:
	Room();
	Room(int type);
	Room(int location, int type, Suspect suspects[]);
	int getLocation()  const;
	void search();
	bool searched;
	Evidence evidence;
	void displayRoom(int pLocation) const;
};
#endif