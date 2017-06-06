#pragma once
#include <string>

class HashTable
{
public:
	HashTable();
	HashTable(unsigned int a_tableSize);
	~HashTable();

	void Add(std::string key, int value);
	int Get(std::string key);
	int& operator[](const std::string a_key);

	//converts input to output (string to unsigned int)
	unsigned int Hash( std::string key );

	int* data;
	unsigned int tableSize;

};

