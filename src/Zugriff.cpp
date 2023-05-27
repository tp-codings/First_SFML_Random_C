#include "Zugriff.h"

Zugriff::Zugriff()
{
	bezugPoint = 10;
	reference = 10;
	pointer = &bezugPoint;
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = i * i / 2 + 4;
	}
}

Zugriff::~Zugriff()
{
}


void Zugriff::zugriffApplication()
{
	//print();
	std::cout << pointer << "\n";
	funPointer(pointer);
	std::cout << pointer << "\n"; 
	funReference(reference);
	funArray(array);

	std::cout << "\nnew print:\n\n\n";
	print();
	std::cout << "\n:\n\n\n";
	std::cout << "\n:\n\n\n";

	int b = 4;
	int* y = &b;
	*y = 9;
	b = 6;

	std::cout << *y << "\n";
	std::cout << y << "\n";
	std::cout << b << "\n";

	
}

void Zugriff::print()
{
	std::cout << "Pointer: " << bezugPoint << "\n\n";
	std::cout << "Reference: " << reference << "\n\n";
	std::cout << "Array: " << "\n";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << i <<".: " << array[i] << "\n";
	}
}

int Zugriff::funPointer(int *value)
{
	std::cout << value <<"\n";
	*value += 1;
	std::cout << value << "\n";
	return 0;
}

int Zugriff::funReference(int &value)
{
	value++;
	return 0;
}

int Zugriff::funArray(int value[])
{
	value[4] = 0;
	return 0;
}


