#include<iostream>
#include<stdio.h>

using namespace std;

// Time complexity is O(N 2)
// space complixty is O(1)
void bubblesort(int a[],int n)
{
	int sorted = false;
	for(int i=0;i<n;i++)
	{
		if(sorted == true)
			break;
		sorted = true;
		for(int j=0;j< n-i-1;j++)
		{
			if(a[j+1] < a[j])
			{
				int x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
				sorted  = false;
			}
		}
	}
}

// Time complexity O(N 2) worst case and O(N) best case when list is already sorted
void insertionsort(int a[], int len)
{
	for(int i=1;i<len;i++)
	{
		int value = a[i];
		int j = i-1;
		while(j >= 0 && a[j]>value)
			{a[j+1]=a[j];j--;}
		a[j+1] = value;
	}
}

int partition(int a[],int l,int h)
{
	int p = a[l];		// pivot
	int left = l;		// letftwall
	for(int i=l+1;i <= h ;i++)
	{
		if(a[i] < p)
		{
			left ++;
			int temp = a[left];
			a[left]= a[i];
			a[i] = temp;
		}
	}
	int temp = a[l];
	a[l]= a[left];
	a[left] = temp;

return left;
}

void quicksort(int a[],int p ,int r)
{
	int pivot;
	if(p<r)
	{
		pivot = partition(a,p,r);
	quicksort(a,p,pivot-1);
	quicksort(a,pivot+1,r);
	}
}

void merge(int a[],int low, int mid, int end,int len)
{
	int *helper = new int[len];		// helper array
	for(int i=low;i<=end;i++)
	{
		helper[i] = a[i];
	}
	int l = low;
	int r = mid+1;
	int cur = low;
	while(l< mid+1 && r<end+1)
	{
		if(helper[l] <= helper[r])
		{
			a[cur] = helper[l];
		l++;
		}
		else if(helper[l] > helper[r])
		{
			a[cur]=helper[r];
		r++;
		}
/*		else if(a[l] == a[r])
		{
			a[cur++]=helper[l];
			a[cur]=helper[r];
		l++; r++;
		}*/
	cur++;
	}

	// copy the element left from left side array .. elements from right are already sorted and placed on back ..
	int rem = mid - l;
	for(int j = 0 ; j<= rem;j++)
	{
		a[cur+j] = helper[l+j];
	}

delete [] helper;
}
void mergesort(int a[],int p, int r,int len)
{
	if ( p < r)
	{
		int m = (p+r)/2;
		mergesort(a,p,m,len);
		mergesort(a,m+1,r,len);
		merge(a,p,m,r,len);
	}
}


int main()
{
	int a[] = {7,5,2,1,4,10,21,11,3};
	int len = 9;
//	bubblesort(a,15);
/*	for(int i =0;i <15;i++)
	{
		printf("%d \n",a[i]);
	}*/
//	int x =binarysearch(a,0,14,7);
//	if(x > -1)
//		printf("Found at %d\n",x);
	//quicksort(a,0,14);
//	mergesort(a,0,len-1,len);
	insertionsort(a,len);
	for(int i =0;i <len;i++)
	{
		printf("%d \n",a[i]);
	}
return 0;

}
