/* Check whether string has unique character or not */ 
//if yes then remove the Unique character 

#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<cstring>

using namespace std;

map<char ,int> st;

void Remove(char *str)
{
    int i =0;
    while(str[i] != '\0')
    {
        str[i] = str[i+1];
        i++;
    }	
}

// Using Map
void FindDupMap(char * str)				// Using Map
{
    while(*str != '\0')
    {
        map<char ,int>:: iterator it = st.find(*str);
        if(it == st.end())
            st[*str] = 1;
        else
        {	
            cout<< " This string has No Unique character from method 1 "<<*str<<endl; remove(str) ;str--;
        }
    str++;
    } 
    cout<<"This string has Unique character from method 1"<<endl;
}

// Sorting the String 
void FindDupSort(char * str,int s)
{
    int count = 0;
    int i = 0;
/*	while(str[i] != '/0')
    {
            count++;
    i++;
    }*/
    int flag =1 ;
    // Bubble Sort	
    for(i=0;i<s-1;i++)
    {
        for(int j=0;j<s-i-1;j++)
        {
            if(str[j] > str[j+1])
            {
                int x = str[j];
                str[j]= str[j+1];
                str[j+1] = x;
            }
        }	
    }
    //cout<<str<<endl;

    for(i=1;i<s-1 ;i++)
    {
        if(str[i]== str[i-1])
            {
                cout<<"String is not Unique by method2"<<endl; return;
            }
    }
    cout<<"The string is unique by method 2 "<<endl;
}

void RemoveDup(char *str,int n)
{
    int i = 0;	//
    int j = 1;
    int k = 0;
    int arr[256] = {0};
    arr[str[i]] = 1;
    while(j <= n)
    {
        if(arr[str[j]] > 0)
            j++;
        else
        {	
            arr[str[j]] = 1;
            i++;
            str[i] = str[j];
            j++;
        }
    }
    cout<<str<<endl;
}

// Using bit vector
// we are using 32 bit of vector saving lots of memory
bool isUniqueChars(string str) 
{ 
    int checker = 0; 
    for (int i = 0; i < str.length(); ++i) 
    { 
        int val = str[i] - 'a'; 
        if ((checker & (1 << val)) > 0) return false; // checking if that positing bit is already set or not.. 
        checker |= (1 << val); 	// setting the position of bit
    } 
    return true; 
}

struct dupMap
{
    unsigned short int bit :1;	// unique bit size
};

//typedef dupMap map1;

void IsUniqueBitvector(string str)
{
    struct dupMap Map[26];
    for(int i=0;i<26;i++)
    {
            Map[i].bit = 0;
    }
    cout<<sizeof(Map[0])<<endl;
    
    for(int i=0 ; i<str.length(); i++)
    {
        int index = str[i] - 'a';
        if(Map[index].bit != 0)
            {
                cout<<"Not Unique"<<endl; return ;
            }
        Map[index].bit =1;
    }

    cout<<"Unique"<<endl;
return;
}

int main()
{
	
    string str = "abcdbe" ;
    //char *stp =  new char[str.size()];
    //strcpy(stp , str.c_str()); 
    //cout<<stp[0]<<endl;
    char * ptr = (char *)str.c_str();

    IsUniqueBitvector(str);
    //FindDupMap(ptr);
//	RemoveDup(ptr,12);
//	printf("%s \n", ptr);
/*	if(isUniqueChars(str))
            cout<<"Unique"<<endl;
    else
            cout<<"Not Unique"<<endl;


    //char *p = (char*)str.c_str();
    //FindDupSort(p, str.size());
*/
return 0;
}
