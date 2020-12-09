#include "Evidence.h"
#include <ctime>
#include <cstdlib>
#include "House.h"
#include <iostream>



Evidence::Evidence()
{
	isWeapon=true;
	hasBlood=true;
	fingerPrints="0000";
}

Evidence::Evidence(int seed, Suspect suspects[])
{
	//srand(time(0));
	if (rand()%2==0) isWeapon=true;
	else isWeapon=false;
	hasBlood=false;
	fingerPrints=suspects[rand()%6].getFingerPrints();
}

void Evidence::displayEvidence() const
{
	cout<<endl;
	if (isWeapon)
		cout<<"Evidence is a weapon."<<endl;

	else
		cout<<"Evidence is not a weapon."<<endl;

	if (hasBlood)
		cout<<"It has blood on it"<<endl;

	else
		cout<<"There is no blood on it."<<endl;

	cout<<"There are fingerprints: "<<fingerPrints<<endl;
}