#include "DynamicArray.h"
#include "LinkedList.h"
#include "BinaryTree.h"

void TestDynamicArray();
void TestLinkedLists();
void TestBinaryTrees();

void main()
{
	//test our dynamic array
	//TestDynamicArray();
	
	//test our linked lists
	//TestLinkedLists();

	//test our Binary trees
	TestBinaryTrees();

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

	//add two numbers
	numbers.PushBack(1);
	numbers.PushBack(2);

	//print out details
	std::cout << "Count: " << numbers.count << std::endl;
	numbers.Print();
}

void TestBinaryTrees()
{
	BinaryTree numberTree;
	numberTree.Insert(3);
	numberTree.Insert(2);
	numberTree.Insert(5);
	numberTree.Insert(4);
	numberTree.Insert(10);
	numberTree.Insert(2);

	numberTree.PrintNodes();
	std::cout << std::endl;
}