#include "DynamicArray.h"
#include <assert.h>

#define DEFAULTCAPACITY 10
//create a default size int array on the heap
DynamicArray::DynamicArray() // : defaultCapacity(10)
{
	//create array on the heap
	data = new int[DEFAULTCAPACITY];

	//update defaultcapacity
	capacity = DEFAULTCAPACITY;

	//update size
	size = 0;
}

DynamicArray::DynamicArray(unsigned int startCapacity) // : defaultCapacity(startCapacity)
{
	//create new array on the heap
	data = new int[startCapacity];

	//update default capacity
	capacity = startCapacity;

	//update size
	size = 0;
}

DynamicArray::~DynamicArray()
{
	//delete our memory
	delete[] data;
}

//add value to the data array
void DynamicArray::Push(int a_value)
{
	//check if size == capacity - 1
		//resize data array
	if (size == capacity - 1)
	{
		Resize(capacity + 10);
	}

	//copy a_value into array slot "size"
	data[size] = a_value;

	//increase size by 1
	size++;
}

void DynamicArray::Insert(int a_value, int a_index)
{
	int temp;

	//checks if index is within array size
	if (a_index <= size)
	{
		temp = data[size];
		Push(temp);

		for (int i = size; i > a_index; i--)
		{
			data[i] = data[i - 1];
		}
		
		data[a_index] = a_value;
	}

	//adds to end of array if index is garbage
	else
	{
		Push(a_value);
	}

}

//prints entire array
void DynamicArray::Print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "|" << data[i];
	}
	std::cout << std::endl;
}

//sorts in ascending order
void DynamicArray::Sort()
{
	bool isSorted = false;
	while (isSorted != true)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (data[i] > data[i + 1])
				{
					int temp = data[i];

					data[i] = data[i + 1];

					data[i + 1] = temp;
				}

				else
				{
					isSorted = true;
				}
			}
		}
	}
}

void DynamicArray::RemoveAt(int a_index)
{
	//checks if a_index is within array size
	if (a_index <= size)
	{
		for (int i = a_index; i < size; i++)
		{
			//set i to i++
			data[i] = data[i + 1];
		}
		size--;
	}
}

void DynamicArray::Remove(int a_value)
{
	for (int i = 0; i < size; i++)
	{
		if (a_value == data[i])
		{
			RemoveAt(i);
		}
	}
}

int DynamicArray::Find(int a_value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == a_value)
		{
			return i;
		}
	}

	std::cout << "Value not found!" << std::endl;

}

void DynamicArray::Clear()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

//resize data to new capacity
void DynamicArray::Resize(unsigned int a_newCapacity)
{
	//if new capacity == 0, throw an error
	assert(a_newCapacity != 0);
	
	//1. make a new array on the heap of newcapacity size
		//store pointer newData
	int* newData = new int[a_newCapacity];

	//2. copy data from old array to new array
		//if size > newCapacity
			//loop to newCapacity when copying
	if (size > a_newCapacity)
	{
		for (int i = 0; i < a_newCapacity; i++)
		{
			newData[i] = data[i];
		}
	}
		//else
			//loop to size
	else
	{
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
	}

	//3. delete old data at data*
	delete[] data;
	
	//4. copy pointer from newData into data
		//data = newData
	data = newData;

}