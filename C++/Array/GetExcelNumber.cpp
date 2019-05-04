#include <iostream>
#include <ctype.h>

using namespace std;
 
string GetExcelColoumn(int i)
{
	if (i <= 0) return "";
 	string retStr = "";
 	while (i > 26)
	{
  		int j = i % 26;
		if(j == 0)
			j = 26;
		char z = 'A' + j - 1;
  		retStr =  z + retStr;
  		i = (i - j)/ 26;
 	}
 	if (i > 0)
 	{
		char z = 'A' + i - 1;
  		retStr =  z + retStr;
 	} 
 return retStr;
}

int GetExcelNumber(string s) 
{
	for(int i=0;i< s.length();i++)
		s[i] = toupper(s[i]);

	int num=0;
	for (int i=0; i<s.length(); i++)
	{
	    char c = s[i];
	    num = num*26 + (c - 'A' + 1); // +1 because A is required for 1
	}
return num;
}

string GetExcelString (int num)
{
	string s = "";
	while (num > 0)
	{
	    char c = (char)((int)'A' + (num-1)%26);
	    s = c + s;
	    num = num - (num-1)%26; // reduce the quantity which is processed already.
	    num = num/26;
	}
return s;
}

int main()
{
cout << GetExcelColoumn(703) << endl;
cout << GetExcelString(703) << endl;
cout<<GetExcelNumber("AAA")<<endl;
 return 0;
}


