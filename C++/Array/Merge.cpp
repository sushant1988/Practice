#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* Merge Three Sorted Element */

struct node
{
	int index;
	int *arr;
	int size;
};

// Find min will return min element on which position. it
int findmin(struct node a[])
{
	int min = -1;
	if(a[0].index != -1)
	{
		if(a[1].index != -1)
		{
			if(a[0].arr[a[0].index] <= a[1].arr[a[1].index])	// comparing data of both array data
			{
				if(a[2].index != -1)
					(a[0].arr[a[0].index] <= a[2].arr[a[2].index]) ? min = 0 : min = 2;
				else
					min = 0;
			}
			else
			{
				if(a[2].index != -1)
					(a[1].arr[a[1].index] <= a[2].arr[a[2].index]) ? min = 1 : min = 2;
				else
					min = 1;
			}
		}
		else
		{
			if(a[2].index != -1)
				(a[0].arr[a[0].index] <= a[2].arr[a[2].index]) ? min = 0 : min = 2;
			else
				min = 0;
		}
	}
	else
	{
		if(a[1].index != -1)
		{
			if(a[2].index != -1)
				(a[1].arr[a[1].index] <= a[2].arr[a[2].index]) ? min = 1 : min = 2;
			else
				min = 1;
		}
		else
			(a[2].index != -1) ? min = 2 : min = -1;
	}
return min;
}

int* Merge(int r[], int b[], int c[], int N1, int N2, int N3)
{
	struct node a[3];

// Initializing Min heap of Size 3 as we are merging only 3 sorted arrays

	// If array is empty index will be -1
	(N1 == 0) ? a[0].index = -1 : a[0].index = 0;
	a[0].size = N1;
	a[0].arr = r;

	// If array is empty index will be -1
	(N2 == 0) ? a[1].index = -1 : a[1].index = 0;
	a[1].size = N2;
	a[1].arr = b;

	// If array is empty index will be -1
	(N3 == 0) ? a[2].index = -1 : a[2].index = 0;
	a[2].size = N3;
	a[2].arr = c;

	int *result = new int[N1+N2+N3];
	int curr = 0;
	while(a[0].index != -1 || a[1].index != -1 || a[2].index != -1)
	{
		int min = findmin(a);
		result[curr] = a[min].arr[a[min].index];
		a[min].index++;
		if(a[min].index == a[min].size)
			a[min].index = -1;
	curr++;
	}
return result;
}

/* ----------- Merge n- Sorted vector using min heap -------------------------*/
struct Node {
	int currElementIndex;	// Index
	vector<int>* v;
};

struct MinHeapComparator {
	bool operator() (const struct Node *a, const struct Node *b) {
		return a->v->at(a->currElementIndex) > b->v->at(b->currElementIndex);
	}
};

struct Node * CreateNode(vector<int> *v, int currElementIndex) {
	struct Node * nw = new struct Node;
	nw->v = v;
	nw->currElementIndex = currElementIndex;
	return nw;
}

vector<int> MergeNew(vector< vector<int> > &sortedVector)
{
	vector<struct Node*> MinHeap;
	vector<int> output;

	// Initialize Heap
	for(int i = 0; i < sortedVector.size(); i++) {
		MinHeap.push_back(CreateNode(&sortedVector[i], 0));
	}

	make_heap(MinHeap.begin(), MinHeap.end(), MinHeapComparator());
	while(!MinHeap.empty()) {
		pop_heap(MinHeap.begin(), MinHeap.end(), MinHeapComparator());
		struct Node *minElement = MinHeap.back();
		int element = minElement->v->at(minElement->currElementIndex++);

		output.push_back(element);
		if (minElement->currElementIndex >= minElement->v->size())
			MinHeap.pop_back();
		push_heap(MinHeap.begin(), MinHeap.end(), MinHeapComparator());
	}
	return output;
}


int main()
{
	int a[] = {3, 7, 11};
	int b[] = {5, 9, 12, 16};
	int c[] = {1, 2, 4, 6, 8};
	int d[] = {2, 4, 5, 7, 9, 10};

/*	int *result = new int[5];
	result = Merge(a, b ,c, 3, 3, 4);
	for(int i=0 ; i<10; i++)
		cout<<result[i]<<endl;
*/
	vector<int> v1(a, a+3);
	vector<int> v2(b, b+4);
	vector<int> v3(c, c+5);
	vector<int> v4(d, d+6);

	vector< vector<int> > final;
	final.push_back(v1);
	final.push_back(v2);
	final.push_back(v3);
	final.push_back(v4);

	vector<int> v = MergeNew(final);

	for(int i=0; i < v.size(); i++) {
		cout<<v[i]<<endl;
	}
return 0;
}





