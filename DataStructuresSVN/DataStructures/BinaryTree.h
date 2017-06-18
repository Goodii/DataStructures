#pragma once

class BinaryTreeNode
{
public:
	BinaryTreeNode(int a_data);
	
	void PrintPreOrder();
	void PrintPostOrder();
	void PrintInOrder();
	
	bool hasLeft()
	{
		return (left != nullptr);
	}
	bool hasRight()
	{
		return (right != nullptr);
	}

	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

};

class BinaryTree
{
public:
	BinaryTree();
	BinaryTreeNode* root;
	BinaryTreeNode* currentNode;

	void PrintNodes();

	bool Find(int a_data);
	BinaryTreeNode* FindNode(int a_data);
	void Insert(int a_data);
	void Remove(int a_data);
};