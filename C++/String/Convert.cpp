	// Convert string to float

#include<iostream>

using namespace std;

// Convert String to Float
float convertF(string x)
{
	float number =0;
	int flag = 1;
	if(x.length() != 0)
	{
		int i =0;
		int p=0;

		int d =1;
		int f=0;
		if(x[0] == '-')
		{
			flag = -1;
			i = 1;
		}
		while(i < x.length())
		{
			if(x[i] == '.' && f == 1)
			{
				cout<<"invalid number"<<endl;
				return 0;
			}
			else if(x[i] == '.' && f != 1)
			{
				p = i;
				i++;
				f=1;
			}
			if(p != x.length()-1)
			{
				number = number*d + (x[i] - '0');
				d = 10;
			}
		i++;
		}

		int fact = 1;
		for(int r=0;r< x.length()-1-p;r++)
		{
			fact = fact *10;
		}
		number = number/fact;
	}
return (number*flag);
}

// Convert Float to string
string convertS(float number)
{
	string x="";
	if(number<0)
	{
		x= '-';
		number = (-number);
	}
	string z ="";
	int flag = 0;
	int value = (int) number;
	number = number - value;
	while(value > 0)
	{
		int r = value % 10;
		value = (value - r) / 10;
		char c = '0' + r;
		z = c + z;
	}
	if(number > 0)
	{
		z = z + '.';
		int v = 0;
		while(number > 0)
		{
			v = number * 10;
			number = (number * 10) - v;
			char c = '0' + v;
			z = z + c;
		}
	}
return (x+z);
}

int S_atoi(string s)
{
	int l = s.length();
	int fac =1;
	int num =0;
	char *x = (char*) s.c_str();
	for(int i=l-1;i>=0;i--)
	{
		num = num + (x[i]-'0') * fac;
		fac = fac*10;
	}
return num;
}

int StringToInteger(string str)
{
	int len = str.length();
	int num = 0;
	bool negFlag = false;
	for(int i=0; i<len;i++) {
		if(str[i] == '-') {
			negFlag = true;
			continue;
		}
		num = num*10 + (str[i] - '0');
	}
	if (negFlag) return (-1) * num;
	return num;
}

// Generate Reverse Fibonacci
void GenerateReverseFib(int x, int y)
{
//	f(n) = f(n-1) + f(n-2)
// f(n-2) = f(n) - f(n-1)

	int curVal = x;
	int newVal = y;
	cout<<curVal<<endl;
	while(curVal) {
		cout<<newVal<<endl;
		int temp = newVal;
		newVal = curVal - newVal;
		curVal = temp;
	}
}

int main()
{
/*	float z = -22.56;
	string s = "-2003";
	string f = "-12.75";

	cout<<"String "<<s<<" to Float "<<convertF(f)<<endl;
	cout<<"Float "<<z<<" to String "<<convertS(z)<<endl;
	cout<<"String "<<s<<" to Integer "<<S_atoi(s)<<endl;
	cout<<"String "<<s<<" to Integer "<<StringToInteger(s)<<endl;*/
	GenerateReverseFib(80, 50);
return 0;
}
