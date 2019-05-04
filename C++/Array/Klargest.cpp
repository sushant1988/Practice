#include<iostream>

using namespace std;

int findpivot(int a[], int l, int h)
{
	int mid = a[l];
	int d = l;
	for(int i=l+1;i<=h;i++)
	{
		if(a[i] < mid)
		{
			d++;
			int temp = a[i];
			a[i] = a[d];
			a[d] = temp;
		}
	}
	int temp = a[l];
	a[l] = a[d];
	a[d] = temp;
return d;
}

// to Find Kthe Largest Element in array
int find(int a[], int K , int l , int h)
{	
	if(l<h)
	{
		int m = findpivot(a,l,h);
		if(m+1 == K)
			return a[m];
		else if(m+1 > K)
			return (find(a,K,0,m-1));
		else
			return (find(a,K,m+1,h));
	}		
return 0;
}

// Find the element in Sorted array that is rotated many times
int FindRotatedSortedArray(int a[], int start, int end, int data)
{
	int mid = (start+end)/2;
	if(a[mid] == data)
		return mid;

	if(end < start)
		return -1;
	else if(a[mid] > a[start])	// left side is in Sorted order
	{
		if(a[mid] >= data && a[start] <= data)
			return FindRotatedSortedArray(a, start, mid-1, data);
		else
			return FindRotatedSortedArray(a, mid+1, end, data);
	}
	else if(a[mid] < a[start])	// right side is in sorted order
	{
		if(a[mid] <= data && a[end] >= data)
			return FindRotatedSortedArray(a, mid+1, end, data);
		else
			return FindRotatedSortedArray(a, start, mid-1, data);
	}	
	else if(a[start] == a[mid])	// All element are repeated
	{
		if (a[mid] != a[end])	
			return FindRotatedSortedArray(a, mid+1, end, data);
		else
		{
			int result = FindRotatedSortedArray(a, start, mid-1, data);
			if(result == -1)
				return FindRotatedSortedArray(a, mid+1, end, data);
			else
				return result;
		}
	}
return -1;
}


int main()
{
	int a[] = {7,1,3,8,4,2,6,9};

	int b[] = {8, 13, 15, 18,2,5,7};

	cout<<"2nd Largest Ellement "<<find(a,7,0,7)<<endl;
//	cout<<FindRotatedSortedArray(b, 0, 6, 7)<<endl;
}
