/*
https://www.geeksforgeeks.org/shortest-common-supersequence/

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int SCS(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    int result[m + 1][n + 1];

    // Finding LCS
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                result[i][j] = 0;
            
            else if (str1[i - 1] == str2[j - 1])
                result[i][j] = 1 + result[i - 1][j - 1];
            
            else 
                result[i][j] = max(result[i - 1][j], result[i][j - 1]);
        }
    }

    // printing shortest common subsequence
    int i = m;
    int j = n;
    string seq = "";
    while (i > 0 && j > 0)
    {
        if(str1[i - 1] == str2[j - 1])
        {
            seq.push_back(str1[i - 1]);
            i--;
            j--;
        }

        else 
        {
            if(result[i][j - 1] >= result[i - 1][j])
            {
                seq.push_back(str2[j - 1]);
                j--;
            }

            else
            {
                seq.push_back(str1[i - 1]);
                i--; 
            }
        }
    }
    while(i > 0)
    {
        seq.push_back(str1[i - 1]);
        i--;
    }
    
    while (j > 0)
    {
        seq.push_back(str2[j - 1]);
        j--;
    }
    
    reverse(seq.begin(), seq.end());
    cout<<seq<<endl;

    // SCS logic
    int superlength = m + n - result[m][n];
    return superlength;
}

int main()
{   
    string str1 = "TGGATE";
    string str2 = "GXAXTYE";
    
    cout<<SCS(str1, str2);
    return 0;
}