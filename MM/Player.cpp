#include "Player.h"
#include "Room.h"
#include <iostream>

Player::Player()
{
}
Player::Player(int type)
{
	playerType=type;
	plocation=0;
	complete=false;
}

void Player::changeLocation(int plocation, Room room)
{
	this->plocation=plocation;
	if(!room.searched)
		room.search();
}

int Player::getLocation()  const
{
	return plocation;
}

void Player::identifyKiller(string killer)
{
	if (killer=="NotAKiller"){
		cout<<"You win."<<endl;}

	else if(killer=="Me" || killer=="me"){
		cout<<"Of course! It was so obvious! People like you make me sick!"<<endl;}

	else{
		cout<<"Nope. That's not the killer. The killer got away with it."<<endl;
		cout<<"The accused will spend 30 years in prison. I hope you're happy."<<endl;}

	complete=true;
}

int Player::getPlayerType() const
{
	return playerType;
}