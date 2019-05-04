z#include<iostream>
#include<vector>

using namespace std;

//Get factorial of a number
int fact(int n) {
	if(n == 1)
		return 1;
	else
		return n * fact(n-1);
}

// Iterative solution
int factL(int n) {
	int fact = 0;
	for (int i = 1; i <= n; i++) {
		fact = fact * n;
	}
}

// Get Fibonaci
int fib(int n) {
	if (n <= 2) return 1;
	else return fib(n-1) + fib(n-2);
}

// dynamic solution
map<int, int> _map;
map<int, int>::iterator _it;
int fib(int n) {
	if(n <= 2) return 1;
	else {
		_it = _map.find(n);
		if(_it != _map.end()) {
			return _it->second;
		} else {
			_map[n] = fib(n-1) + fib(n-2);

		}
		return _map[n];
	}
}

// To find the square root of the element to approx value
double sqrt(double x)
{
	if(x < 0) return -1;
	if (x == 0 || x == 1) return x;

	double precision = 0.0001;
	double start =0;
	double end = x;			// 0<sqrt(x)<x

	// 0
	if (x < 1)
		end = 1;
	while(end-start > precision)
	{
		double mid = (start+end)/2;
		double midsqr = mid *mid;
		if(midsqr == x)
			return mid;
		else if(midsqr > x)
			end = mid;
		else
			start = mid;
	}

return (start+end)/2;
}

// To find the GDC of number
int GCD(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return (GCD(b,a%b));
}

// To Find the Power of Number
int Pow(int x, int n)
{
	if(n == 1)
		return x;
	if(n % 2 == 0)
		return (Pow(x, n/2) * Pow(x, n/2));
	else
		return (x * Pow(x, n/2) * Pow(x, n/2));
}

// swap element in array
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Dutch National Flag Problem
// partition such that [bottom]<= low <= [middle] <= high <= [top]
void ThreeWayPartition(int data[], int size, int low, int high)
{
	int p = -1;
	int q = size;

	for(int i=0; i< q;)
	{
		if(data[i] < low)
		{
			swap(&data[i], &data[++p]);
			i++;
		}
		else if(data[i]>= high)
		{
			swap(&data[i], &data[--q]);
		}
		else
			i++;
	}
}

//Sort the Three different element in an array 0,1,2
// Dutch National Flag Problem
void SortThreeElement(int a[], int arr_size)
{
   int lo = 0;
   int hi = arr_size - 1;
   int mid = 0;

   while(mid <= hi)
   {
      switch(a[mid])
      {
         case 0:
           swap(&a[lo++], &a[mid++]);
           break;
         case 1:
           mid++;
           break;
         case 2:
           swap(&a[mid], &a[hi--]);
           break;
      }
   }
}

//O(n) and space as well O(n)
//Find the three increasing number such that i,j,k and a[]
void FindIncreasingNumber(int a[], int size)
{
	int *greater = new int[size];
	int *smaller = new int[size];

	int max = a[size-1];
	int max_i = size-1;

	for(int i=size-1; i>=0;i--)
	{
		if(a[i] > max)
		{
			max = a[i];
			max_i = i;
			greater[i] = max_i;
		}
		else
			greater[i] = max_i;
	}

	int min = a[0];
	int min_i = 0;

	for(int i=0; i<size;i++)
	{
		if(a[i] < min)
		{
			min = a[i];
			min_i = i;
			smaller[i] = min_i;
		}
		else
			smaller[i] = min_i;
	}

	for(int t= 1; t< size-1;t++)
	{
		if(smaller[t] < t && greater[t] > t)
		{
			cout<<smaller[t]<<","<<t<<","<<greater[t]<<" ";
			cout<<a[smaller[t]]<<","<<a[t]<<","<<a[greater[t]]<<endl;
		break;
		}
	}
}

// an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to buy one share of the stock and sell one share of the stock, design an algorithm to find the best times to buy and sell.
void getBestTime(int stocks[], int sz, int &buy, int &sell)
{
	int min = 0;
	int maxDiff = 0;
	buy = sell = 0;
	for (int i = 0; i < sz; i++)
	{
    		if (stocks[i] < stocks[min])
      			min = i;
    		int diff = stocks[i] - stocks[min];
    		if (diff > maxDiff)
			{
     		 	buy = min;
     			sell = i;
     			maxDiff = diff;
    		}
  	}
}

// Generate Reverse Fibonacci
void GenerateReverseFib(int x, int y)
{
	int cur = x;
	int newval = y;
	cout<<cur<<endl;
	while(newval) {
		int temp = newval;
		newval = cur - newval;
		cur = temp;
		cout<<newval<<endl;
	}
}
// Get Next smallest number with same digit greter than the current number

// Get the largest number with same digit smaller than current number

// Generate Prime number

int main()
{
	/*
	double x = 50;

	int a[] = {1,4,12,21, 6, 7,3,9,2,5,10};
	cout<<"Square Root of "<<x<<" : "<<sqrt(x)<<endl;
	cout<<"GCD of Number : "<<GCD(100,60)<<endl;
	cout<<"Power of Number : "<<Pow(2, 9)<<endl;
	ThreeWayPartition(a,10, 4, 8);
	int arr[] = {29, 85, 53, 128, 33, 4, 77};
	FindIncreasingNumber(arr, 7);
//	for(int i=0; i<10;i++)
//		cout<<a[i]<<" ";
*/
GenerateReverseFib(80, 30);
return 0;
}
