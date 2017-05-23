#pragma once
class Stack
{
public:
	Stack();
	Stack(int a_size);
	~Stack();
	
	//returns true is size is 0
	bool IsEmpty() const;
	//returns the size (how many items on our stack)
	int GetSize() const;
	//adds a_value to the top of our stack(end of array)
	void Push(int a_value);
	//removes last value from the array
	int Pop();
	//returns the data of the last value in the array
	int Top();

private:
	int* data;
	int capacity; //how many spots
	int size; //how many used elements

};

