#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Seach Array Implementation
int binarysearch(int a[],int l,int r, int n)
{
	if(r<l)
		return -1;
	else {
		int mid = (l+r)/2;
		if(a[mid] == n)
			return mid;
		else if(a[mid] < n)
			return binarysearch(a,mid+1,r,n);
		else
			return binarysearch(a,l,mid,n);
	}
	return -1;
}

/* ---- Sort the Array by Frequency-------------- */
typedef struct element {
		int index;
		int freq;
} Node;

Node *create_node(int index, int freq)
{
	Node *nw = new Node;
	nw->index = index;
	nw->freq = freq;

	return nw;
}

struct myclass {
  bool operator() (Node *i, Node *j) { return (i->freq < j->freq);}
} myobject;

// O(n log n) time and O(n) space
void PrintFreq(int a[], int len)
{
	unordered_map<int, int> mapr;
	unordered_map<int, int>::iterator it;

	//O(n) time and space
	for(int i=0; i<len; i++) {
		it = mapr.find(a[i]);
		if(it != mapr.end()) {
			(it->second)++;
		} else {
			mapr[a[i]] = 1;
		}
	}
	//O(n) time and space
	vector<Node *>v;
	for(it = mapr.begin(); it != mapr.end(); it++) {
		v.push_back(create_node(it->first, it->second));
	}

	// O(n log n) time
	sort(v.begin(), v.end(), myobject);

	// O(n) time
	for(int i=0; i< v.size(); i++) {
		cout<<"Key: "<<v[i]->index<<" Freq: "<<v[i]->freq<<endl;
	}
	return;
}

/* --------------Sort Array of String by Frequency----------------------------*/

typedef struct strelement {
	string index;
	int freq;
} NodeStr;

NodeStr *create_node_str(string index, int freq)
{
	NodeStr *nw = new NodeStr;
	nw->index = index;
	nw->freq = freq;

	return nw;
}

struct myclassstr {
  bool operator() (NodeStr *i, NodeStr *j) {
	  if (i->freq == j->freq) {
		if (i->index.compare(j->index) > 0 ) return false;
		else return true;
	  }
	  return (i->freq > j->freq);
	}
} myobjectstr;

// O(n log n) time and O(n) space
void PrintFreqStr(const vector<string> &a, int len)
{
	unordered_map<string, int> mapr;
	unordered_map<string, int>::iterator it;

	//O(n) time and space
	for(int i=0; i<len; i++) {
		it = mapr.find(a[i]);
		if(it != mapr.end()) {
			(it->second)++;
		} else {
			mapr[a[i]] = 1;
		}
	}

	//O(n) time and space
	vector<NodeStr *>v;
	for(it = mapr.begin(); it != mapr.end(); it++) {
		v.push_back(create_node_str(it->first, it->second));
	}

	// O(n log n) time
	sort(v.begin(), v.end(), myobjectstr);

	// O(n) time
	for(int i=0; i< v.size(); i++) {
		cout<<v[i]->index<<":"<<v[i]->freq<<endl;
	}
	return;
}

/*---------------------------------------------------------*/

int main() {
 //   int a[] = {7,5,2,7,1,4,2,1,2,3};
//	int len = 9;
//    int x = binarysearch(a,0,9,10);
//    if(x > -1)
//        printf("Found at %d\n",x);
//	PrintFreq(a, 9);
	vector<string> v;

	v.push_back("orange");
	v.push_back("straberry");

	v.push_back("pear");
	v.push_back("grape");
	v.push_back("pear");
	v.push_back("grape");
	v.push_back("pear");
	v.push_back("orange");
	v.push_back("apple");


	PrintFreqStr(v, v.size());

    return 0;
}