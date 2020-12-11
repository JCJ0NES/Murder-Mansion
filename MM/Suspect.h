#ifndef SUSPECT_H
#define SUSPECT_H
#include <string>
using namespace std;

class Suspect
{
private:
	int attractiveness;
	string fingerPrints;
	int hairColor;
	int height;
	bool isKiller;
	string name;
	int suspicionLevel;
	int weight;
public:
	Suspect();
	Suspect(int notKiller);
	void displaySuspect() const;
	int getAttractiveness()  const;
	string getFingerPrints()  const;
	int getHairColor()  const;
	int getHeight()  const;
	bool getKiller()  const;
	string getName()  const;
	int getSuspicionLevel()  const;
	int getWeight()  const;
	void setSuspicionLevel(int num);
};
#endif