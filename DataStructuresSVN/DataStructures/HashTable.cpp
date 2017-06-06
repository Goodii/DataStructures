#include "HashTable.h"



HashTable::HashTable() //overload with tableSize
{
	//create arry of ints at data based on tableSize
	tableSize = 10;

	data = new int[tableSize];
}

HashTable::HashTable(unsigned int a_tableSize)
{
	data = new int[a_tableSize];
}

HashTable::~HashTable()
{
	//delete array
	delete[] data;
}

void HashTable::Add(std::string key, int value)
{
	//hash key using hash function
	unsigned int hashedKey = Hash(key);

	//use modulus to map the hashed key to a value between 0 and tableSize-1
	unsigned int index = hashedKey % tableSize;

	data[index] = value;
}

//access
int HashTable::Get(std::string key)
{
	//hash the key, using same hash function
	unsigned int hashedKey = Hash(key);

	//convert key to index between 0 and tableSize-1
	unsigned int index = hashedKey % tableSize;

	return data[index];
}

int& HashTable::operator[](const std::string key)
{
	//hash the key, using same hash function
	unsigned int hashedKey = Hash(key);

	//convert key to index between 0 and tableSize-1
	unsigned int index = hashedKey % tableSize;

	return data[index];
}

unsigned int HashTable::Hash(std::string key)
{
	//convert key to unsigned int
	unsigned int hashedKey = 0;

	for (int i = 0; i < key.size(); i++)
	{
		hashedKey += (unsigned int)key[i];
	}
	
	return hashedKey;
}