#pragma once
#include <iostream>

using namespace std;

class DArray
{
private:
	int numberOfItems, maxcap;
	float* data;
	float magnitude;

public:
	DArray();
	~DArray();
	void addItem(float item);
	void removeItem(int index);
	float getItem(int index);
	bool indexIsOutOfBounds(int index);
	void display();
	DArray* add(DArray* rhs);
	float calculateMagnitude();
	DArray* normalise();
	float dotProduct(DArray* rhs);
};

