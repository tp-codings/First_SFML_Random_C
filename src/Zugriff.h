#pragma once
#include <iostream>

class Zugriff
{
public:
	Zugriff();
	~Zugriff();

	void zugriffApplication();

private:

	int funPointer(int *value);
	int funReference(int &value);
	int funArray(int value[]);
	void print();

	int* pointer;
	int reference;
	int bezugPoint;
	int array[10];
};

