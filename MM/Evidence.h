#ifndef EVIDENCE_H
#define EVIDENCE_H
#include <string>
#include "Suspect.h"

using namespace std;

class Evidence
{
public:
	Evidence();
	Evidence(int seed, Suspect suspects[]);
	string fingerPrints;
	bool isWeapon;
	bool hasBlood;
	void displayEvidence() const;
};
#endif