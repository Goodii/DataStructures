#include "DynamicArray.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "HashTable.h"
#include "Stack.h"

void TestDynamicArray();
void TestLinkedLists();
void TestBinaryTrees();
void TestHashTable();
void TestStack();

void main()
{
	//test our dynamic array
	//std::cout << "Dynamic Array" << std::endl; TestDynamicArray();
	
	//test our linked lists
	//std::cout << "Linked Lists" << std::endl; TestLinkedLists();

	//test our Binary trees
	//std::cout << "Binary Tree" << std::endl; TestBinaryTrees();

	//tests stack
	std::cout << "Stack" << std::endl; TestStack();

	//test Hash table
	//std::cout << "Hash Table" << std::endl; TestHashTable();
}

void TestDynamicArray()
{
	//test construction
	//DynamicArray testArray1;
	
	//test overloaded constructor
	DynamicArray testArray1(20);

	//add values to our dynamic array
	for (int i = 0; i < 20; i++)
	{
		testArray1.Push(i);
	}


	std::cout << "Original:" << std::endl;
	testArray1.Print();
	std::cout << std::endl;

	//insert
	std::cout << "Insert 100 at index 5:" << std::endl;
	testArray1.Insert(100, 5);
	testArray1.Print();
	std::cout << std::endl;

	std::cout << "Insert 555 at index 10:" << std::endl;
	testArray1.Insert(555, 10);
	testArray1.Print();
	std::cout << std::endl;

	std::cout << "Insert 1 at index 25(larger than array size):" << std::endl;
	testArray1.Insert(1, 25);
	testArray1.Print();	
	std::cout << std::endl;

	//[] operator overload
	std::cout << "Sub-script operator overload, element 5 = 1:" << std::endl;
	testArray1[5] = 1;
	testArray1.Print();
	std::cout << std::endl;

	//RemoveAt
	std::cout << "Remove At 5: " << std::endl;
	testArray1.RemoveAt(5);
	testArray1.Print();
	std::cout << std::endl;

	std::cout << "Remove At 10: " << std::endl;
	testArray1.RemoveAt(10);
	testArray1.Print();
	std::cout << std::endl;

	std::cout << "Remove At 25 (invalid index): " << std::endl;
	testArray1.RemoveAt(25);
	testArray1.Print();
	std::cout << std::endl;

	//Remove(int)
	std::cout << "Remove int 3:" << std::endl;
	testArray1.Remove(3);
	testArray1.Print();
	std::cout << std::endl;

	std::cout << "Remove int 25 (non-existent):" << std::endl;
	testArray1.Remove(25);
	testArray1.Print();
	std::cout << std::endl;

	//Find(value)
	int index;
	std::cout << "Returns index of int 4: ";
	index = testArray1.Find(4);
	std::cout << index << std::endl;

	//Find(invalid value)
	std::cout << "Returns index of int 25: ";
	index = testArray1.Find(25);
	std::cout << std::endl;
	
	//Sort
	std::cout << "Sorted array:" << std::endl;
	testArray1.Sort();
	testArray1.Print();
	std::cout << std::endl;

	//Clear
	std::cout << "Cleared array:" << std::endl;
	testArray1.Clear();
	testArray1.Print();
	std::cout << std::endl;

	//test overloader constructor
	//DynamicArray testArray2(20);

}

void TestLinkedLists()
{
	//create linkedlist
	LinkedList numbers;

	//print out details
	std::cout << "PushBack(1),(2),(3),(4)" << std::endl;
	numbers.PushBack(1);
	numbers.PushBack(2);
	numbers.PushBack(3);
	numbers.PushBack(4);
	numbers.Print();

	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//add number to start
	std::cout << std::endl << "PushFront(0)" << std::endl;
	numbers.PushFront(0);
	numbers.Print();
	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//remove number at index 2
	std::cout << std::endl << "Remove( at index 2 )" << std::endl;
	numbers.Remove(2);
	numbers.Print();
	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//insert number at index 1
	std::cout << std::endl << "Insert(10 at index 1)" << std::endl;
	numbers.Insert(10, 1);
	numbers.Print();
	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//remove first number
	std::cout << std::endl << "PopFront" << std::endl;
	numbers.PopFront();
	numbers.Print();
	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//remove last number
	std::cout << std::endl << "PopBack" << std::endl;
	numbers.PopBack();
	numbers.Print();

	//print out count
	std::cout << "Count: " << numbers.count << std::endl;

	//return start node
	std::cout << std::endl << "Return Start Node address: " << numbers.begin() << std::endl;

	//return last node
	std::cout << std::endl << "Return Last Node address: " << numbers.end() << std::endl;
}

void TestBinaryTrees()
{
	BinaryTree numberTree;

	std::cout << "Original order : ";

	//inserts 10 random values
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 10;
		std::cout << " " << value << " ";
		numberTree.Insert(value);
	}

	//insert additional number
	numberTree.Insert(5);
	std::cout << " 5 ";

	//prints pre, post and in order nodes
	std::cout << std::endl;
	numberTree.PrintNodes();

	//find number
	bool numberFound = numberTree.Find(5);
	std::cout << "Is number found: " << numberFound << std::endl;

	//removes number
	numberTree.Remove(5);
	
	//searches for removed number
	numberFound = numberTree.Find(5);
	std::cout << "Is number found: " << numberFound << std::endl;

}

void TestHashTable()
{
	HashTable data;

	data.Add("John Smith", 2);
	data.Add("Johnny Joestar", 3);

	std::cout << data.Get("John Smith") << std::endl;
	std::cout << data.Get("Johnny Joestar") << std::endl;
	
	data["Num1"] = 1;
	std::cout << data["Num1"] << std::endl;

	data.Add("John Smith", 11);
	std::cout << data.Get("John Smith") << std::endl;
}

void TestStack()
{
	Stack stackData;

	//checks if stack is empty
	std::cout << "IsEmpty: " << stackData.IsEmpty() << std::endl;

	//adds number to top of the stack
	std::cout << "Push (0 - 9)" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		stackData.Push(i);
	}

	//returns the size (amount of items on stack)
	std::cout << "GetSize: " << stackData.GetSize() << std::endl;

	//removes value from top of stack
	std::cout << "Pop" << std::endl;
	stackData.Pop();

	//returns the size (amount of items on stack)
	std::cout << "GetSize: " << stackData.GetSize() << std::endl;

	//returns value at the top of the stack
	std::cout << "Top: " << stackData.Top() << std::endl;

	//returns the size (amount of items on stack)
	std::cout << "GetSize: " << stackData.GetSize() << std::endl;

	//checks if stack is empty
	std::cout << "IsEmpty: " << stackData.IsEmpty() << std::endl;

}