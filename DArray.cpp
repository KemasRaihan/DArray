#include "DArray.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

DArray::DArray()
{
	numberOfItems = 0;
	size = 1;
	maxcap = 10;
	data = (float*)malloc(sizeof(float) * size);
}


DArray::~DArray()
{
	free(data);
}

void DArray::addItem(float item)
{
	/*grow array*/
	if (numberOfItems < maxcap)
	{
		size *= 2;
		data = (float*)realloc(data, sizeof(float) * size);
		data[numberOfItems++] = item; // add item to the array 
	}
	else
	{
		cout << "\nVector has reached max capacity.\n";
	}

	
}

void DArray::removeItem(int index)
{
	if (index >= 0 && index < maxcap)
	{
		for (int i = index; i < numberOfItems; i++)
		{
			data[i] = data[i + 1];
		}
		numberOfItems--;
	}
}

float DArray::getItem(int index)
{
	if (index >= 0 && index < maxcap)
	{
		return data[index];
	}
	return NULL;
}


void DArray::display()
{
	cout << "\n[";
	for (int i = 0; i < numberOfItems; i++)
	{
		cout << data[i] << ",";
	}
	cout << "]\n";
}


DArray* DArray::add(DArray* rhs)
{
	DArray* result = new DArray();
	if (numberOfItems == rhs->numberOfItems)
	{
		for (int i = 0; i < numberOfItems; i++)
		{
			//result->data[i] = data[i] + rhs->data[i];
			// the code below works because numberOfItems parameter is incremented when add() is used
			result->addItem(data[i] + rhs->data[i]); 
		}
		return result;
	}

	return nullptr;

}

float DArray::calculateMagnitude()
{
	float sumOfSquares = 0;

	for (int i = 0; i < numberOfItems; i++)
	{
		sumOfSquares += data[i] * data[i];
	}

	float magnitude = sqrt(sumOfSquares);
	//cout << "\nMagnitude is " << magnitude;

	return magnitude;
}

DArray* DArray::normalise()
{
	DArray* result = new DArray();
	for (int i = 0; i < numberOfItems; i++)
	{
		result->data[i] = data[i] / calculateMagnitude();
	}

	return result;
}

float DArray::dotProduct(DArray* rhs)
{
	float result = 0;

	if (numberOfItems == rhs->numberOfItems)
	{
		for (int i = 0; i < numberOfItems; i++)
		{
			result += data[i] * rhs->data[i];
		}
		return result;
	}

	return -1;
}

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	DArray* d1 = new DArray();
	d1->addItem(2.0f);
	d1->addItem(8.0f);
	d1->addItem(7.0f);
	d1->addItem(2.5f);

	cout << "\nd1 before removal : ";
	d1->display();

	d1->removeItem(3);
	cout << "\nd1 after removal : ";
	d1->display();
	
	delete d1;
	d1 = nullptr;

	return 0;
}