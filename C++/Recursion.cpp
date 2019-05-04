#include<iostream>

using namespace std;

// Making change problem
int MakeChange(int n, int denom)
{
    int nextdenom = 0;

    switch(denom)
    {
        case 25:
                    nextdenom = 10;
                    break;
        case 10: 	
                    nextdenom = 5;
                    break;
        case 5:
                    nextdenom = 1;
                    break;
        case 1:
                    return 1;

    }
    int ways = 0;
    for(int i = 0; i*denom <= n;i++)
    {
        ways += MakeChange(n-i*denom, nextdenom);
    }
return ways;
}


int main()
{
    cout<<MakeChange(100, 25)<<endl;

return 0;
}
