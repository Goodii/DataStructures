#pragma once

class LinkListNode;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	//adds to end of list
	void PushBack(int value);
	//adds to start of list
	void PushFront(int value);
	//removes at index
	void Remove(int a_index);
	//inserts at index
	void Insert(int a_value, int a_index);
	//removes first item
	void PopFront();
	//removes last item
	void PopBack();
	//returns first node
	LinkListNode* begin();
	//returns last node
	LinkListNode* end();
	
	void Print();
	//pointer to our first node
	LinkListNode* start;
	int count; //size

};

class LinkListNode
{
public:
	LinkListNode();
	LinkListNode(int a_data);

	int data; //T data;
	LinkListNode* next;
	LinkListNode* previous; //doubly linked list
};