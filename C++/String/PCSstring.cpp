#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

// To generate permutation
void Permutation(char *a, int focus, int length)
{
    if(focus == length-1)
    {
        for(int i =0;i<length;i++)
            cout<<a[i];
        cout<<endl;
    return;
    }

    Permutation(a, focus+1, length);

    for(int i = focus+1;i<length;i++)
    {
        char temp = a[i];
        a[i] = a[focus];
        a[focus] = temp;

        Permutation(a, focus+1, length);
    }
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string.
   permute(str, 0, n-1);
   O(n* n!) as n! permutations
*/

// swap element in array
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(a[l], a[i]);
          permute(a, l+1, r);
          swap(a[l], a[i]); //backtrack
       }
   }
}

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
void printParenthesis(string s, int open, int close)
{
    if(!open && !close) {
        cout<<s<<endl;
    }
    if(open) {
        printParenthesis(s+"(", open-1, close+1);
    }
    if(close) {
        printParenthesis(s+")", open, close-1);
    }
}

//(0, n, 0, 0)
void _printParenthesis(int pos, int n, int open, int close)
{
#define MAX_SIZE 256
  static char str[MAX_SIZE];

  if(close == n)
  {
    printf("%s \n", str);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
#undef MAX_SIZE
}

// To generate Combination
vector<char> comb;
void Combs(char *a, int offset, int k, int N)
{
    if(k == 0)
    {
        for(int i=0; i < comb.size(); i++)
            cout<<comb[i];
    cout<<endl;
    return;
    }

    for(int i=offset; i <= N-k; i++)
    {
        comb.push_back(a[i]);
        Combs(a, i+1, k-1, N);
        comb.pop_back();
    }
}

// To Generate Combination
//O(N2)
void Combination(string str, int len, int K)
{
    int totalSubset = ((1<<len) -1);
    int temp;
    while(totalSubset !=0)
    {
        temp = totalSubset;
        int count = 0;
        vector<char> tmpVec;
        int arrIndex=0;
        while(temp)
        {
            if(temp & 1) {
                count++;
                tmpVec.push_back(str[arrIndex]);
            }
        temp >>= 1;
        arrIndex++;
        }
        if(count == K) {
            // print the vector
            for(int j=0; j<tmpVec.size(); j++) {
                cout<<tmpVec[j];
            }
            cout<<endl;
        }
    totalSubset--;
    }
}

// To generate all Subset which 2 to power N
void PrintSubset(char *a, int N)
{
    int totalSubset = pow(2, N)-1;
    int temp;
    while(totalSubset !=0)
    {
        temp = totalSubset;
        cout<<"{ ";
        for(int i=0; i<N; i++)
        {
            if(temp & 1)
                cout<<a[i]<<" ";
        temp >>= 1;
        }
        cout<<"}"<<endl;
    totalSubset--;
    }
}

string substr(const char* a, int j, int i)
{
	string z = "";
	for (int k =0; k<i;k++)
		z = z+a[j+k];

	return z;
}

// to generate all the unique subset from string
void PrintAllSubstring(string str)
{
	int n = str.length();
	for(int i=1;i<= n;i++)
	{
		for(int j=0;j<= n-i;j++)
		{
			string x = substr(str.c_str(), j, i);
			cout<<x<<endl;
		}
	}
}

// Function to print all sub strings
void subString1(char str[], int n)
{
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                cout << str[k];

            cout << endl;
        }
    }
}

// Function to print all sub strings
// My own solution
// Time Complexity O(N^3)
void subString(char str[], int n)
{
    // Pick ending point
    for (int i = 0; i < n; i++)
    {
        // Pick starting point
        for (int j = 0; j <= i; j++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            for (int k = j; k <= i; k++) {
                cout << str[k];
            }
            cout << endl;
        }
    }
}

/* All the permutation of letter with lower and upper case
AB -> ab, Ab, aB, AB */

bool ischar(char x) {
  return ((x >= 65 && x <= 90) || ( x >= 97 && x <= 122));
}

void stringPermutation(string str, int focus) {
  if(focus == str.length()) {
    //vec.push_back(str);
    cout<<str<<endl;
    return;
  }

  if(ischar(str[focus])) {
    for(int i = 0; i < 2; i++) {
      if(i) {
        str[focus] =  (char) (str[focus] ^ ' ');     // converting into lower case
        stringPermutation(str, focus+1);
      } else {
         stringPermutation(str, focus+1);
      }
    }
  } else {
    stringPermutation(str, focus+1);
  }
}

int main()
{
	char s[] = {'A','B','C'};
 //   char s[] = "ABC"
//	Permutation(s, 0, 4);
//	Combs(s,0,3,4);
//	PrintSubset(s, 3);
//	PrintAllSubstring("ABCD");
//subString(s, 4);
//permute(s, 0, 2);
//printParenthesis("", 3, 0);

//string x = "A1B23CD";
//stringPermutation(x, 0);
string str = "ABC";
Combination(str, str.length(), 1);
return 0;
}
