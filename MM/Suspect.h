#ifndef SUSPECT_H
#define SUSPECT_H
#include <string>
using namespace std;

class Suspect
{
private:
	string name;
	int height;
	int weight;
	int hairColor;
	string fingerPrints;
	int suspicionLevel;
	int attractiveness;
	bool isKiller;
public:
	Suspect();
	Suspect(int seed);
	string getName()  const;
	int getHeight()  const;
	int getWeight()  const;
	int getHairColor()  const;
	string getFingerPrints()  const;
	int getSuspicionLevel()  const;
	int getAttractiveness()  const;
	void setSuspicionLevel(int num);
	bool getKiller()  const;
	void displaySuspect() const;
};
#endif