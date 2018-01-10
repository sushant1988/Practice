/*
	Max or Min heap are priority queues
	building heap O(NlogN)  as insertion takes O(logN) overall take O(N)
	extractmin = O(log N)
	increase key O(log N)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;


/* ----------------- Max Heap Class ----------- */
class MaxHeap{

private:

	vector<int> heap;
	int HSize;

	void BuildMaxHeap()
	{
		for(int i = (HSize-1)/2 ; i >= 0 ; i--)
		{
			MaxHeapify(i);
		}
	}

	void MaxHeapify(int i)
	{
		int l = Left(i);
		int r = Right(i);
		int largest = i;
		if (l != -1 && heap[l]>heap[largest])
			largest = l;
		if (r != -1 && heap[r]>heap[largest])
			largest = r;
		if (largest != i)
		{
			int temp = heap[i];
			heap[i] = heap[largest];
			heap[largest] = temp;
			MaxHeapify(largest);
		}
	}

	int Parent(int i)
	{
		if(i < 0)
			return -1;
		return i/2;
	}

	int Left(int i)
	{
		if(2*i+1 > HSize-1)
			return -1;
		return 2*i+1;
	}

	int Right(int i)
	{
		if(2*i+2 > HSize-1)
			return -1;
		return 2*i+2;
	}
public:
	 MaxHeap(int a[],int len)
	{
		int i =0;
		while(i<len)
			{heap.push_back(a[i]);i++;}
		HSize = heap.size();
		BuildMaxHeap();
	}

	void Insert(int data)
	{
		heap.push_back(data);
		HSize ++;
		IncreaseKey(HSize-1, data);
	}

	void Display()
	{
		for(int i=0;i<heap.size();i++)
			cout<<heap[i]<<endl;
	}

	int ExtractMax()
	{
		int max = heap[0];
		heap[0]= heap[HSize-1];
		heap.pop_back();
		HSize--;
		MaxHeapify(0);
	return max;
	}

	void HeapSort()
	{
		for(int i=HSize-1;i>=0;i--)
		{
			int temp = heap[0];
			heap[0]=heap[i];
			heap[i] = temp;
			HSize--;
		MaxHeapify(0);
		}
	}

	void IncreaseKey(int index, int key)
	{
		if(heap[index] <= key)
		{
			heap[index] = key;
			while(index>0 && heap[Parent(index)] < heap[index])
			{
				int temp = heap[index];
				heap[index] = heap[Parent(index)];
				heap[Parent(index)] = temp;
			index = Parent(index);
			}
		}
	}

	~MaxHeap()
	{
		heap.clear();
	}

	void PrintLevelwise()
	{
	}

};

/* ----------- Max or Min Heap STL --------- */


struct minHeapComparator {
		bool operator() (const int& a, const int& b) const {
			return a > b;
	}
};

void Heap()
{
	int A[] = {5,4,3,6,10,8 ,9,11};
	vector<int> v (A, A + sizeof(A)/sizeof(int));

	make_heap(v.begin(), v.end(), minHeapComparator());

	v.push_back(1);
	push_heap(v.begin(), v.end(), minHeapComparator()); // heapify

// Heap Sorting here
	while(!v.empty()) {
		cout<<"Top element "<<v.front()<<endl;
		pop_heap(v.begin(), v.end(), minHeapComparator()); // heapify
		v.pop_back();
	}

return;
}

/* ------------ Heap Sort -------------------*/

/* ------------ Top K Elements --------------*/
/* using Min heap to get topK element */
struct Node {
	string word;
	int freq;
	Node(string words, int freqs) {
		word = words;
		freq = freqs;
	}
};

struct MinHeapComparator {
	bool operator () (const struct Node *item1, const struct Node *item2) {
		return item1->freq > item2->freq;
	}
};

// Total time is O(K) + O(N) + O(K log K) + O(N log K) = O(N log K)
void TopKElements(vector<string> words, int topK)
{
	unordered_map<string , int> Map;
	unordered_map<string, int>::iterator it;
	// O(N) space and time complexity
	for(int i=0; i < words.size(); i++) {
		it = Map.find(words[i]);
		if(it != Map.end()) it->second++;
		else Map[words[i]] = 1;
	}
	vector<Node *> heap;
	int count = 0;
	//O(K)
	for(it = Map.begin(); it != Map.end(); it++) {
		if(count == topK) break;
		heap.push_back(new Node(it->first, it->second));
		count++;
	}
	// O(K log K) time
	make_heap(heap.begin(), heap.end(), MinHeapComparator());

	// O(N log K)
	while(it != Map.end()) {
		struct Node *top = heap.front();
//		cout<<it->first<<" "<<it->second<<endl;
		if(it->second > top->freq) {
			pop_heap(heap.begin(), heap.end(), MinHeapComparator());		// O(log K)
			top->freq = it->second;
			top->word = it->first;
			push_heap(heap.begin(), heap.end(), MinHeapComparator());		// O(log K)
		}
		it++;
	}
	for(int i=0; i<heap.size(); i++) cout<<heap[i]->word<<" "<<heap[i]->freq<<endl;
	return ;
}

/* -------------------------------------------*/
int main()
{
//	int A[] = {5,4,3,6,10,8 ,9,11};
//	MaxHeap h(A,8);
//	int max = h.ExtractMax();
//	h.Insert(7);

//	h.HeapSort();
//	h.Display();

//	Heap();
string Sentence = "Hi My name is sushant What is your name is there something i can do about you";
vector<string> words;
stringstream str(Sentence);
while(str) {
	string subs;
	str >> subs;
	words.push_back(subs);
}
TopKElements(words, 2);

return 0;
}
