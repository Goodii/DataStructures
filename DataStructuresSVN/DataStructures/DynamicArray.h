#pragma once
#include <iostream>

//create dynamically resizing array of intergers
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int startCapacity);
	~DynamicArray();

	//add a_value to the array
	void Push(int a_value);
	
	//insert a_value at a_index, move all values after a_index forward
	void Insert(int a_value, int a_index);

	//remove at index, shift array
	void RemoveAt(int a_index);
	
	//find first instance of a_value and remove that
	void Remove(int a_value);

	//returns index of first a_value;
	int Find(int a_value);

	//resize 
	void Resize(unsigned int a_newCapacity);
	
	//prints contents of array
	void Print();

	//sorts array, ascending order
	void Sort();

	//access array
	int& operator[](int index)
	{
		return data[index];
	}

	//wipes all data to default value;
	void Clear();

private:
	//contents/data (address of array of integers on the heap)
	int* data;
	//used items
	unsigned int size;
	//how much space do we have
	unsigned int capacity;

	//const int defaultCapacity;
	
};

