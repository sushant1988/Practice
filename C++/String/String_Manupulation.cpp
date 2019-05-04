// Reversing the string

#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

// Reverse the string using pointer
void ReversePtr(char *str)
{
    char *end = str;
    while(*end != '\0' )
        end++;
    end--;
    while(str < end)
    {
        char temp = *end;
        *end = *str;
        *str = temp;
    end --;
    str++;
    }
}

//Recursive solution to reverse string
void ReverseRec(char *st,int s,int n)
{
    if(s <= n)
    {
        int temp = st[s];
        st[s] = st[n];
        st[n] = temp;
        ReverseRec(st,s+1,n-1);
    }
}

// Appending the string to reverse
string ReverseApp(char *s)
{
    string x = "";
    for(int i =0;i<7;i++)
        x = s[i]+x;
return x;
}

// Reverse a word ..
void Reverse(char *start, char *end)
{
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
    start++;
    end--;
    }
}

// Reverse by Word
void ReverseWrd(char *str)
{
    ReversePtr(str);
    char * start = str;
    char *end = str;
    while(*str != '\0')
    {
        if(*str == ' ')
        {
            Reverse(start, str-1);
            start = str+1;
        }
    str++;
    }
    end = str-1;
    Reverse(start, end);
}


void ReverseWord1(char *str)
{
    char * start = str;
    char *end = str;
    while(*str != '\0')
    {
        if(*str == ' ')
        {
            Reverse(start, str-1);
            start = str+1;
        }
    str++;
    }
    end = str-1;
    Reverse(start, end);
}

// To Lower
char ToLower(char str)
{
    if(str >= 65 && str <= 91)
        return ((str - 65) + 97);
    else
        return str;
}

// To Lower
/* 6th bit in lower case is set to 1
and space has value 32 and 1<< 5 swap the case with xor*/
char ToLowerBitWise(char str)
{
    if(str >= 65 && str <= 91)
        return (str ^ ' ');
    else
        return str;
}

// Is Palindrom without case sensitive
bool IsPalindrom(char *str)
{
    char *end = str;
    while(*end != '\0')
            end++;
    end--;

    while(str <= end)
    {
        while(*str == ' ')
            str++;

        while(*end == ' ')
            end--;

        if(ToLower(*str) != ToLower(*end))
        {
            return false;
        }
    str++;
    end--;
    }
return true;
}

// To find the longest Palindrome in a string
// O(N2) time complexity
int LongestPalindrome(string str)
{
    int maxLength = 0;
    int start = 0;
    int end = 0;

    for(int k=0;k< str.length(); k++)
    {
        // when string length is odd
        int i = k;
        int j = k;
        int count = 1;
        while(str[i] == str[j] && i >=0 && j< str.length())
        {
            count = count + 2;
            i--;
            j++;
        }
        if(count > maxLength)
        {
            maxLength = count;
            start = ++i;
            end = --j;
        }

        // when string length is even
        i=k;
        j=i+1;
        count = 0;
        while(str[i] == str[j] && i >=0 && j< str.length())
        {
            count = count + 2;
            i--;
            j++;
        }
        if(count > maxLength)
        {
            maxLength = count;
            start = ++i;
            end = --j;
        }
    }
    cout<<"Start Position "<<start<<endl;
    cout<<"End Position "<<end<<endl;

    return maxLength;
}

// String Subset s1, s2
// Function to check if characters in "b" are a subset // of the characters in "a"
int isSubset(char *a, char *b)
{
    int letterPresent[256];
    int i;
    for(i=0; i<256; i++)
        letterPresent[i]=0;
    for(i=0; a[i]!='\0'; i++)
        letterPresent[a[i]]++;
    for(i=0; b[i]!='\0'; i++)
        if(!letterPresent[b[i]])
            return(1);
    return(0);
}

/*
reduced pair : he can delete any pair of adjacent letters with same value.
he will repeat the above operation as many times as it can be performed.
aaabccddd -- abd
baab - Empty String
*/
string super_reduced_string(string s)
{
    // Complete this function
    int count = 1;
    string z;
    for(int i=1; i < s.length(); i++) {
        if(s[i] == s[i-1]) count++;
        else {
            if(count%2) z += s[i-1];
            count = 1;
        }
    }
    if(count%2) z += s[s.length()-1];
    if(z.empty()) return "Empty String";
    if(s.length() != z.length())
        return super_reduced_string(z);

    return z;
}

// using stack
string super_reduced_string1(string s)
{
    stack<char> stk;
    for(int i=0; i<s.length(); i++) {
        if(!stk.empty() && stk.top() == s[i])
            stk.pop();
        else
            stk.push(s[i]);
    }
    if(stk.empty()) return "Empty String";
    string x;
    while(!stk.empty()) {
        x = stk.top() + x;
        stk.pop();
    }
    return x;
}


string reduce_string(string input_string) {
  //TODO: COMPLETE ME
    string z = "";
    z = z + input_string[0];
    for(int i = 1; i < input_string.length(); i++) {
        if (input_string[i] != input_string[i-1])
            z = z + input_string[i];
    }

    return z;
}

//MINIMUM WINDOW string
// MiniMum Window to find all the char of pattern in other one too
// Returns false if no valid window is found. Else returns
// true and updates minWindowBegin and minWindowEnd with the
// starting and ending position of the minimum window.
bool minWindow(const char* S, const char *T,
               int &minWindowBegin, int &minWindowEnd) {
  int sLen = strlen(S);
  int tLen = strlen(T);
  int needToFind[256] = {0};

  for (int i = 0; i < tLen; i++)
    needToFind[T[i]]++;

  int hasFound[256] = {0};
  int minWindowLen = INT_MAX;
  int count = 0;
  for (int begin = 0, end = 0; end < sLen; end++) {
    // skip characters not in T
    if (needToFind[S[end]] == 0) continue;
    hasFound[S[end]]++;
    if (hasFound[S[end]] <= needToFind[S[end]])
      count++;

    // if window constraint is satisfied
    if (count == tLen) {
      // advance begin index as far right as possible,
      // stop when advancing breaks window constraint.
      while (needToFind[S[begin]] == 0 ||
            hasFound[S[begin]] > needToFind[S[begin]]) {
        if (hasFound[S[begin]] > needToFind[S[begin]])
          hasFound[S[begin]]--;
        begin++;
      }

      // update minWindow if a minimum length is met
      int windowLen = end - begin + 1;
      if (windowLen < minWindowLen) {
        minWindowBegin = begin;
        minWindowEnd = end;
        minWindowLen = windowLen;
      } // end if
    } // end if
  } // end for

  return (count == tLen) ? true : false;
}

int main()
{
 //   string str = "rat t aR" ;
 //   int n = 4;
 //   char * x = (char*) str.c_str();
/*	ReversePtr(x);
    cout<<"String Reverse by Pointer :"<<x<<endl;
    ReverseRec(x,0,n);
    cout<<"String Reverse by Recusion :"<<x<<endl;

    cout<<"String Reverse by Appending :"<<ReverseApp(x)<<endl;

    string s = " The quick      brown fox ";
    char * st =  (char*) s.c_str();
    ReverseWord1(st);
    cout<<"Word Reverse :"<<st<<endl;

    if(IsPalindrom(x))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;
*/
//	char c = 'C';
//	cout<<ToLowerBitWise(c)<<endl;
 //   string x = "forgeeksskeegfor";
 //   cout<<"Longest Palindrome "<<LongestPalindrome(x)<<endl;
//    string s = "aa";
//    string result = super_reduced_string1(s);
 //   cout << result << endl;
 string y = "asdheeeeskaeeeleee";
 cout<<reduce_string(y)<<endl;
return 0;
}
