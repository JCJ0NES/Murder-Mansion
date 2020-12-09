#include "Suspect.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Suspect::Suspect()
{
	name="NotAKiller";
	height=60;
	weight=150;
	hairColor=0;
	fingerPrints="0000";
	suspicionLevel=100;
	attractiveness=1;
	isKiller=true;
}

Suspect::Suspect(int seed)
{
	//srand(time(0)+seed);
	string names[]={"Jazmine", "Naomi", "Quiana", " Fran", "Nicholas", "Arletta", "Maegan", "Sabine", "Gidget", "Breanna",
		"Arminda", "Jc", "Markita", "Jonie"};
	name=names[rand()%14];
	height=48+rand()%30;
	weight=120+rand()%150;
	hairColor=rand()%4;
	char fp[5];
	for (int i=0; i<4; i++){
		fp[i]=33+rand()%90;}
	fp[4] = '\0';
	fingerPrints=fp;
	suspicionLevel=rand()%100;
	attractiveness=rand()%100;
	isKiller=false;
}

string Suspect::getName() const
{
	return name;
}

int Suspect::getHeight()  const
{
	return height;
}

int Suspect::getWeight()  const
{
	return weight;
}

int Suspect::getHairColor()  const
{
	return hairColor;
}

string Suspect::getFingerPrints()  const
{
	return fingerPrints;
}

int Suspect::getSuspicionLevel()  const
{
	return suspicionLevel;
}

int Suspect::getAttractiveness()  const
{
	return attractiveness;
}

void Suspect::setSuspicionLevel(int num)
{
	suspicionLevel=num;
}

bool Suspect::getKiller()  const
{
	return isKiller;
}

void Suspect::displaySuspect() const
{
	cout<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Height: "<<height<<endl;
	cout<<"Weight: "<<weight<<endl;
	if (hairColor==1)
		cout<<"Hair: Brown"<<endl;
	if (hairColor==2)
		cout<<"Hair: Black"<<endl;
	if (hairColor==3)
		cout<<"Hair: Red"<<endl;
	if (hairColor==0)
		cout<<"Hair: Blonde"<<endl;
	cout<<"Fingerprints: "<<fingerPrints<<endl;
	cout<<"Suspicion Level: "<<suspicionLevel<<endl;
	cout<<"Attractiveness: "<<attractiveness<<endl<<endl;
}