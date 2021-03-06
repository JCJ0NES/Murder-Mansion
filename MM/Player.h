#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Room.h"

using namespace std;

class Player
{
private:
	int playerType;
	int plocation;
public:
	Player();
	Player(int type);
	void changeLocation(int location, Room room);
	int getLocation()  const;
	int getPlayerType() const;
	void identifyKiller(string killer);
	
	bool complete;
};
#endif