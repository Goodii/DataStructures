#pragma once

class BinaryTreeNode
{
public:
	BinaryTreeNode(int a_data);
	
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	void PrintPreOrder();
	void PrintPostOrder();
	void PrintInOrder();
	
	int data;

};

class BinaryTree
{
public:
	BinaryTree();
	BinaryTreeNode* root;
	BinaryTreeNode* currentNode;

	void PrintNodes();

	bool Find(int a_data);
	void Insert(int a_data);
	void Remove(int a_data);
};