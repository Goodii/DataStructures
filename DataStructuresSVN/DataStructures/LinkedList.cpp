#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList()
{
	start = nullptr;
	count = 0;
}


LinkedList::~LinkedList()
{
	
}

/*
void LinkedList::PushBack(int value)
{
	//if start is nullptr
		//adding our first node
		//create a new LinkListNode
		//store value in that node
		//set up next and previous pointers

	//add our first node
	if (start == nullptr)
	{
		//create the node on the heap
		LinkListNode* newNode = new LinkListNode();

		//set the node's value
		newNode->data = value;

		//set up the node's pointers
		newNode->next = nullptr;
		newNode->previous = nullptr;

		//point start node at new node
		start = newNode; //copies address
	}

	else //if this is already a start node
	{
		//create node
		LinkListNode* newNode = new LinkListNode();

		//set up its data
		newNode->data = value;
		newNode->next = nullptr; //we know next is null pointer because it is the last node

		//find the final node
		//create a current node pointer - this just holds an address
		LinkListNode* currentNode = start;

		//while currentNode's next is not nullptr (not the end)
			//look at the node attached to this one
		while (currentNode->next != nullptr)
		{
			//start pointing at the next one
			currentNode = currentNode->next;
		}

		//add it to the end of the list
		currentNode->next = newNode; //connect newNode to startNode
		newNode->previous = currentNode;
	}

	//increment count
	count++;
}
*/

void LinkedList::PushBack(int value)
{
	//if start is nullptr; add first node
	if (start == nullptr)
	{
		//create node on the heap
		LinkListNode* newNode = new LinkListNode();

		//set node value
		newNode->data = value;

		//set up node's pointers
		newNode->next = nullptr;
		newNode->previous = nullptr;

		//point start node at new node
		start = newNode;
	}
	//create new LinkListNode
	else
	{
		//create node
		LinkListNode* newNode = new LinkListNode();

		//set up data
		newNode->data = value;
		newNode->next = nullptr;

		//find final node
		LinkListNode* currentNode = start;

		//while currentNode next is not nullptr
		while (currentNode->next != nullptr)
		{
			//start pointing at the next node
			currentNode = currentNode->next;
		}

		//add to end of the list
		//connect newNode to startNode
		currentNode->next = newNode;
		newNode->previous = currentNode;
	}

	//incremement count
	count++;
}

//adds to start of the list
void LinkedList::PushFront(int value)
{
	
}

void LinkedList::Print()
{
	//start at start
	LinkListNode* currentNode = start;
	
	//keep looking at next node until we hit the last node
	while (currentNode != nullptr) //so while looking at a node
	{
		//print the data at the node we are looking at
		std::cout << "[" << currentNode->data << "]" << std::endl;

		//now look at the one attached to the node we just printed
		currentNode = currentNode->next;
	}

}

LinkListNode::LinkListNode()
{
	data = 0;
	next = nullptr;
	previous = nullptr;
}

LinkListNode::LinkListNode(int a_data)
{
	data = a_data;
	next = nullptr;
	previous = nullptr;
}