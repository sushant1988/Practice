#include<iostream>
#include<vector>

using namespace std;


class HashTable
{
	struct HashEntry
	{
		int key;
		int value;
		struct HashEntry *next;
	};

	int SIZE;
	vector<struct HashEntry *> table;

	int HashFunction(int key)
	{
		return (key%SIZE);
	}

	struct HashEntry * CreateHashNode(int key, int value)
	{
		struct HashEntry *nw = new HashEntry;
		nw->key = key;
		nw->value = value;
		nw->next = NULL;	
	}
	
	int findnode(int key, int value, int hash)
	{
		struct HashEntry *temp = table[hash];
		while(temp != NULL)
		{
			if(temp->key == key && temp->value == value)
				return 1;
			temp = temp->next;
		}
	return 0;
	}

public:

	HashTable()
	{
		SIZE = 50;
		table.resize(SIZE);
		for(int i=0; i<SIZE ; i++)
			table[i] = NULL;
	}

	

	void insert(int key, int value)
	{
		int hash = HashFunction(key);
		if(table[hash] == NULL)
			table[hash]= CreateHashNode(key, value);
		else
		{
			if(findnode(key, value, hash) == 0)
			{
				struct HashEntry *temp = CreateHashNode(key, value);
				temp->next = table[hash];
				table[hash] = temp;
			}
		}	
			
	}

	int find(int key, int value)
	{
		int hash = HashFunction(key);
		if(table[hash]!= NULL)
		{
			struct HashEntry *temp ;
			while(temp != NULL)
			{
				if(temp->key == key && temp->value == value)
					{return 1;break;}
			temp = temp->next;
			}
		return 0;
		}
	}

	void Resizing()
	{
		
	}

	~HashTable()
	{
		for(int i=0; i<SIZE; i++)
		{
			struct HashEntry *temp = table[i];
			while(temp != NULL)
			{
				struct HashEntry *temp2 = temp;
				temp = temp->next;
				delete temp2;
			}
		}
	vector.clear();
	}
};


int main()
{
	HashTable *hash = new HashTable();
	
	hash.insert(20, 1);
	hash.insert(55, 5);
	hash.insert(21, 6);
	hash.insert(105, 5);

return 0;
}

