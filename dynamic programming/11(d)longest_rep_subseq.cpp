/*
https://www.geeksforgeeks.org/longest-repeating-subsequence/

Find length of Longest Repearing Subsequence

When both the characters are same in the string they shouldn't present on the same index in two strings.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int repSubseq(string str1)
{  
    string str2 = str1;
    int m = str1.length();

    int result[m + 1][m + 1];

    // LCS logic
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                result[i][j] = 0;
                                              // minor change from LCS
            else if (str1[i - 1] == str2[j - 1] && i != j)
                result[i][j] = 1 + result[i - 1][j - 1];
            
            else
                result[i][j] = max(result[i][j - 1], result[i - 1][j]);
        }   
    }

    // printing longest repeating subsequence
    int i = m;
    int j = m;
    string s = "";

    while( i > 0 && j > 0)
    {
        if(result[i][j] == result[i - 1][j - 1] + 1)
        {
            s.push_back(str1[i - 1]);
            i--;
            j--;
        }
        
        else if(result[i][j] == result[i - 1][j])
            i--;
        else
            j--;
    }

    reverse(s.begin(), s.end());

    cout<<s<<endl;
    return result[m][m];
            // return length of ABD which is repeating in the given string
}

int main()
{   
    string str1 = "AABEBCDD";
    cout<<repSubseq(str1);
    return 0;
}