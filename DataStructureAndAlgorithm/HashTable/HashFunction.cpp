#include <iostream>
using namespace std;
#include <list>
// In midSquare function: we eliminate 2 last digits and get the 4 next digits
long int midSquare(long int seed)
{
	long int result = seed * seed;
	result /= 100;
	result %= 10000;
	return result;	
}

class Hash
{
	int bucket;
	//Pointer to an array containing value
	list<int>* table;
public:
	Hash();
	Hash(int b); // Constructor with 1 argument

	//insert a item into hash table
	void insertItem(int key);

	// delete a item from hash table
	void deleteItem(int key);

	int hashfunction(int a)
	{
		return a % bucket;
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->bucket = b;
	table = new list<int>[bucket];
}

void Hash::insertItem(int key)
{
	int index = hashfunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	//get the hash index of key
	int index = hashfunction(key);

	// find the key in (index) th list
	list <int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key) break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
	{
		table[index].erase(i);
	}

}


void Hash::displayHash()
{
	for (int i = 0; i < bucket; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}


int main()
{
	// array that contains keys to be mapped
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash table
	Hash h(7);   // 7 is count of buckets in
				 // hash table
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	// delete 12 from hash table
	//h.deleteItem(12);

	// display the Hash table
	h.displayHash();

	system("pause");
	return 0;
}