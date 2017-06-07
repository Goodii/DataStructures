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
	//create new node
	LinkListNode* newNode = new LinkListNode;

	//set newNode pointers
	newNode->data = value;
	newNode->previous = nullptr;
	newNode->next = start;

	//set start previous pointer to newNode
	start = newNode;

	count++;
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

void LinkedList::Remove(int a_index)
{
	LinkListNode* currentNode = start;

	//if index is within list size
	if (a_index < count && a_index > 0)
	{
		for (int i = 0; i < a_index; i++)
		{
			currentNode = currentNode->next;
		}

		currentNode->next->previous = currentNode->previous;
		currentNode->previous->next = currentNode->next;

		delete currentNode;

		count--;
	}
}

void LinkedList::Insert(int a_value, int a_index)
{
	LinkListNode* newNode = new LinkListNode;

	newNode->next = nullptr;
	newNode->previous = nullptr;
	newNode->data = a_value;

	LinkListNode* currentNode = start;

	if (a_index < count && a_index >= 0)
	{
		for (int i = 0; i < a_index; i++)
		{
			currentNode = currentNode->next;
		}


		count++;
	}

}

void LinkedList::PopFront()
{
	//set starting node's next previous to nullptr
	//start->next->previous = nullptr;

	start = start->next;

	count--;
}

void LinkedList::PopBack()
{
	LinkListNode* currentNode = start;

	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}

	currentNode->previous->next = nullptr;

	delete currentNode;

	count--;
}

LinkListNode* LinkedList::begin()
{
	LinkListNode* currentNode = start;

	while (currentNode->previous != nullptr)
	{
		currentNode = currentNode->previous;
	}

	return currentNode;
}

LinkListNode* LinkedList::end()
{
	LinkListNode* currentNode = start;

	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}

	return currentNode;
}
