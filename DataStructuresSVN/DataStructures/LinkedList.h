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