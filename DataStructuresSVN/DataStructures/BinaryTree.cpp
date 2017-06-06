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

void BinaryTree::PrintNodes()
{
	if (root != nullptr)
	{
		std::cout << "Pre Order : ";
		root->PrintPreOrder();
		std::cout << std::endl;

		std::cout << "Post Order : ";
		root->PrintPostOrder();
		std::cout << std::endl;

		std::cout << "In Order : ";
		root->PrintInOrder();
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
		left->PrintPostOrder();
	}

	//print right child data
	if (right != nullptr)
	{
		right->PrintPostOrder();
	}

	//print node data
	std::cout << " " << data << " ";
}

void BinaryTreeNode::PrintInOrder()
{
	//print left child data
	if (left != nullptr)
	{
		left->PrintInOrder();
	}

	//print node data
	std::cout << " " << data << " ";

	//print right child data
	if (right != nullptr)
	{
		right->PrintInOrder();
	}
}

bool BinaryTree::Find(int a_data)
{
	//set current node to root
	currentNode = root;

	//while currentNode is not null
	while (currentNode != nullptr)
	{
		//if a_data == currentNode->data
		if (a_data == currentNode->data)
		{
			//return currentNode and parent
			return currentNode;
		}

		else
		{
			//if a_data < currentNode->data
			if (a_data < currentNode->data)
			{
				//set currentNode to left
				currentNode = currentNode->left;
			}
			//else
			else
			{
				//set currentNode to right
				currentNode = currentNode->right;
			}
		}
	}
	return false;
}

void BinaryTree::Remove(int a_data)
{
	//find the node
	currentNode = root;

	if (Find(a_data) == true)
	{
		//if no children
		if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			//remove with no children
			currentNode = nullptr;
		}

		//if two children
		if (currentNode->left != nullptr && currentNode->right != nullptr)
		{
			//find nextNode in sequence
			
			//copy value of nextNode into nodeToRemove
			//call value
		}
	}
}