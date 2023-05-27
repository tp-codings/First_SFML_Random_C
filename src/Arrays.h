#pragma once
class Arrays
{
public:
	Arrays();
	~Arrays();
	void ArrayApplication();
	

private:
	int einD[3];
	int zweiD[3][3];
	int dreiD[3][3][3];

	int initArray(int val, int wahl, int stelle);
	int showArray(int choice);
	int init1D(int val, int stelle);
	int init2D(int val, int stelle);
	int init3D(int val, int stelle);
};

