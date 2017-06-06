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

void LinkedList::Insert(int a_value, int a_index)
{


}

void LinkedList::Remove(int a_index)
{

}

void LinkedList::PopFront()
{

}

void LinkedList::PopBack()
{

}

LinkListNode* LinkedList::begin()
{

}

LinkListNode* LinkedList::end()
{

}
