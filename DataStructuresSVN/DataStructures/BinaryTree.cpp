#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
	//no root node currently, empty tree
	root = nullptr;
}

BinaryTreeNode::BinaryTreeNode(int a_data)
{
	data = a_data;
	left = nullptr;
	right = nullptr;
}

void BinaryTree::Insert(int a_data)
{
	//generate a new node with data
	BinaryTreeNode* newNode = new BinaryTreeNode(a_data);
	
	//if no rootnode, set newNode as root
	if (root == nullptr)
	{
		root = newNode;
	}

	else
	{
		BinaryTreeNode* currentNode;
		currentNode = root;
		//loop over currentNode pointer
		while (true)
		{
			//if newNode < currentNode
			if (newNode->data < currentNode->data)
			{
				//try insert to left ( if leftNode = nullptr )
				if (currentNode->left == nullptr)
				{
					currentNode->left = newNode;
					break;
				}
				else
				{
					//repeat until you've found a free spot
					currentNode = currentNode->left;
					continue;
				}
			}
				
			else
			{
				//try inserting at right
				if (currentNode->right == nullptr)
				{
					currentNode->right = newNode;
					break;
				}
				//repeat until you've found a free spot
				else
				{
					currentNode = currentNode->right;
					continue;
				}
			}
		}
	}
}

void BinaryTree::Find(int a_data)
{
	bool isFound = false;
	while (isFound != true)
	{

	}
}

void BinaryTree::Remove(int a_data)
{
	//find the node
	//if no children
		//remove with no children
	//if two children
		//find nextNode in sequence
		//copy value of nextNode into nodeToRemove
		//call value
}

void BinaryTree::PrintNodes()
{
	if (root != nullptr)
	{
		root->PrintPreOrder();
		std::cout << std::endl;

		root->PrintInOrder();
		std::cout << std::endl;

		root->PrintPostOrder();
		std::cout << std::endl;
	}

}

void BinaryTreeNode::PrintPreOrder()
{
	//print node data
	std::cout << " " << data << " ";

	//print left child data
	if (left != nullptr)
	{
		left->PrintPreOrder();
	}

	//print right child data
	if (right != nullptr)
	{
		right->PrintPreOrder();
	}
}

void BinaryTreeNode::PrintPostOrder()
{
	//print left child data
	if (left != nullptr)
	{
		left->PrintPreOrder();
	}

	//print right child data
	if (right != nullptr)
	{
		right->PrintPreOrder();
	}

	//print node data
	std::cout << " " << data << " ";
}

void BinaryTreeNode::PrintInOrder()
{
	//print left child data
	if (left != nullptr)
	{
		left->PrintPreOrder();
	}

	//print node data
	std::cout << " " << data << " ";

	//print right child data
	if (right != nullptr)
	{
		right->PrintPreOrder();
	}
}
