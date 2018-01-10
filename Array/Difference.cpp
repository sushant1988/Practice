#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

unordered_map<int,int> m;
// facebook : calculate the number of pairs having same difference
int pairs(int a[], int dif, int N)
{
	for(int i=0;i<N;i++)
	{
		if(m.find(a[i]) != m.end())
			m[a[i]] += 1;
		else
			m[a[i]] = 1;
	}
	int count=0;
	unordered_map<int,int>::iterator it;
	for(int i=0;i<N;i++)
	{
		it = m.find(a[i]-dif);
		if( it != m.end())
			count = count + (it->second);
	}
return count;
}


// Find 2 elements with maximum difference in an array
int MaxDiff(int arr[], int len)
{
	int minelem = arr[0];
	int maxdiff = arr[1]-minelem;

	for(int i=1; i<len; i++)
	{
		if(maxdiff < arr[i]-minelem)
			maxdiff = arr[i]-minelem;
		if(minelem > arr[i])
			minelem = arr[i];
	}
return maxdiff;
}

// Calculate Maximum Subarray of list (Maximum sub in contiguous subarray)
int MaxSubArray(int arr[], int len) {
	int sum=0;
	int intsum = 0;

	for(int i=0;i<len;i++) {
		intsum = intsum + arr[i];

		if(intsum < 0) intsum = 0;
		else if(sum < intsum) sum = intsum;
	}

	return sum;
}

// Given an array of (unsorted) integers, arrange them such that a < b > c < d > e... etc.
// O(N) time complexity
void  SortArray(int arr[], int len)
{
    for(int i=1; i<len;i++)
    {
        if(i % 2 == 1)
        {
            if(arr[i]<arr[i-1])
                swap(arr, i, i-1);
        }
        if(i % 2 == 0)
        {
            if(arr[i]>arr[i-1])
               swap(arr, i, i-1);
        }
    }
}


int main()
{
	int a[] = {2,3,4,5,6};
	cout<<"Totals number of paris with difference of 1"<<pairs(a,1,5)<<endl;

	//int arr[] = {30,12,15,22,25,7,18};
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<"Maximum Difference Exists "<<MaxDiff(arr, 7)<<endl;
	cout<<"Maximum SubArry Exists "<<MaxSubArray(arr, 7)<<endl;
return 0;
}
