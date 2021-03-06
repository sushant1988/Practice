#include<iostream>

using namespace std;

// Rabin Karp Method
int FindString(string str, string sub)
{
    int HashSub=0;
    int HashStr = 0;

    for(int i=0; i< sub.length(); i++)
        HashSub += sub[i];

    for(int i=0; i<sub.length(); i++)
        HashStr += str[i];

    for(int i=0; i <= str.length()-sub.length(); i++)
    {
        if(HashStr == HashSub)
        {
            return i;
        }
    HashStr = HashStr - str[i] + str[i+sub.length()];
    }
    return -1;
}

/* WildCard Pattern Matching */
// Function that matches input str with
// given wildcard pattern
bool strmatch(const char str[], const char pattern[],
              int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);

    // lookup table for storing results of
    // subproblems
    bool lookup[n + 1][m + 1];

    // initailze lookup table to false
    memset(lookup, false, sizeof(lookup));

    // empty pattern can match with empty string
    lookup[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            //    to next  character in the pattern,
            //     i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] ||
                               lookup[i - 1][j];

            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[j - 1] == '?' ||
                    str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];

            // If characters don't match
            else lookup[i][j] = false;
        }
    }

    return lookup[n][m];
}

int main()
{
    const char* str = "baabbaaa";
    const char* pattern = "*a*a?a";

//	int x =  FindString(str, sub);

//	cout<<x<<endl;

if (strmatch(str, pattern, strlen(str),
                         strlen(pattern)))
        cout <<   "Yes" << endl;
    else
        cout << "No" << endl;

return 0;
}
