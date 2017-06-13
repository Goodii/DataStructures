#include "Stack.h"


Stack::Stack()
{
	//create 10 free slots
	data = new int[10];
	capacity = 10;
	size = 0;
}

Stack::Stack(int a_size)
{
	data = new int[10];
	capacity = 10;
	size = a_size;
}

Stack::~Stack()
{
	//delete data
	delete[] data;
}

bool Stack::IsEmpty() const
{
	//if size is 0, return true
	return (size == 0);
}

int Stack::GetSize() const
{
	return size;
}

void Stack::Push(int a_value)
{
	//check capacity, resize if necessary
	if (size == capacity)
	{
		capacity++;
	}

	//add our value to the end of the array
	data[size] = a_value;
	size++;
}

int Stack::Pop()
{
	//check if stack is empty
	if (IsEmpty() == false)
	{
		//decrement size (now our stack is technically one less)
		size--;
		//return data at size
		return data[size];
	}
}

int Stack::Top()
{
	return data[size - 1];
}