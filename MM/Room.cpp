#include "Room.h"
#include <iostream>

Room::Room()
{
}

Room::Room(int type)
{
	this->type=type;

		//srand(time(0));
	if (type==1){
		milkBones=0;
		catNip=0;
		bananas=rand()%11;}

	if (type==2){
		milkBones=rand()%11;
		catNip=0;
		bananas=0;}

	if (type==3){
		milkBones=0;
		catNip=rand()%11;
		bananas=0;}

	hasEvidence=rand()%2;

	size=1+rand()%3;
	
	this->location=5;

	Evidence evidence;

	this->evidence=evidence;
	searched=false;
}

Room::Room(int location, int type, Suspect suspects[])
{
	//srand(time(0));
	if (type==1){
		milkBones=0;
		catNip=0;
		bananas=rand()%11;}

	if (type==2){
		milkBones=rand()%11;
		catNip=0;
		bananas=0;}

	if (type==3){
		milkBones=0;
		catNip=rand()%11;
		bananas=0;}

	hasEvidence=rand()%2;

	size=1+rand()%3;

	this->location=location;

	Evidence evidence(location, suspects);

	this->evidence=evidence;
	searched=false;
}

int Room::getLocation() const
{
	return location;
}

void Room::search()
{
	searched=true;
	cout<<endl;

	if (location==5)
		cout<<"Gross. The body is still in here."<<endl;

	if (size==1)
		cout<<"This room is small."<<endl;

	if (size==2)
		cout<<"An average sized room."<<endl;

	if (size==3)
		cout<<"This room is large."<<endl;

	if (type==1 && bananas>0){
		cout<<"Sweet! "<<bananas<<" bananas!"<<endl;}

	if (type==2 && milkBones>0){
		cout<<"Sweet! "<<milkBones<<" Milk Bones!"<<endl;}

	if (type==3 && catNip>0){
		cout<<"Sweet! "<<catNip<<" Cat Nip!"<<endl;}

	cout<<"There is evidence!"<<endl;

	evidence.displayEvidence();

}

void Room::displayRoom(int pLocation) const
{
	if (location<10)cout<<"["<<location<<" ";
	else cout<<"["<<location;
	if (location==pLocation) cout<<" P";
	else cout<<"  ";
	if (searched) cout<<"X";
	else if (!searched) cout<<" ";
	cout<<"]  ";
}