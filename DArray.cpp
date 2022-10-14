#include "DArray.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

DArray::DArray()
{
	numberOfItems = 0;
	maxcap = 10;
	data = (float*)malloc(sizeof(float) * maxcap);
}


DArray::~DArray()
{
	free(data);
}

void DArray::addItem(float item)
{
	/*grow array*/
	if (numberOfItems == maxcap)
	{
		maxcap *= 4;
		data = (float*)realloc(data, sizeof(float) * maxcap);
	}

	data[numberOfItems++] = item; // add item to the array 
}

void DArray::removeItem(int index)
{
	if (!indexIsOutOfBounds(index))
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
	if (!indexIsOutOfBounds(index))
	{
		return data[index];
	}
	return NULL;
}

bool DArray::indexIsOutOfBounds(int index)
{
	try {
		if (index < 0 || index >= numberOfItems) // check index out of bounds exception
		{
			throw index;
		}
		else
		{
			return false;
		}
	}
	catch (int index)
	{
		cout << "Index " << index << " is out of bounds";
		return true;
	}

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
	// change

	cout << "\nd1 before removal : ";
	d1->display();

	d1->removeItem(3);
	cout << "\nd1 after removal : ";
	d1->display();

	float item = d1->getItem(0);
	cout << item;

	//DArray* d2 = new DArray();
	//d2->addItem(-1.0f);
	//d2->addItem(15.0f);
	//d2->addItem(-7.0f);
	//d2->addItem(0.0f);

	//cout << "\nd2 : ";
	//d2->display();

	//DArray* d3 = d1->add(d2);

	//cout << "\nd3 = d1 + d2 : ";
	//d3->display();

	//float md1 = d1->calculateMagnitude();
	//cout << "\nThe magnitude of d1 is " << md1 << "\n";

	//float dd12 = d1->dotProduct(d2);
	//cout << "\nThe dot product of d1 and d2 is " << dd12 << "\n";



	
	delete d1;
	d1 = nullptr;

	//delete d2;
	//d2 = nullptr;

	//delete d3;
	//d3 = nullptr;

	return 0;
}