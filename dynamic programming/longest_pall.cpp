/*
https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

We just used the logic of longest common substring
Here we took an another string variable to store the reverse of the original string 
and then find the LCS of both the strings.

We can also use:
1) reverse(str.begin(), str.end());   // stl function
*/

# include <bits/stdc++.h>

using namespace std;

int LPS(string str1, int n)
{   
    string str2 = str1;  // to store the reverse of original string

    // reverse logic 
    int m = n - 1;
    for(int i = 0; i < n/2; i++)
    {
        swap(str2[i], str2[m]);
        m--;
    }

    // extra space to store the values
    int result[n + 1][n + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <=n; j++)
        {   
            if(i == 0 || j == 0)
                result[i][j] = 0;

            else if(str1[i - 1] == str2[j - 1])
                result[i][j] = 1 + result[i - 1][j - 1];
            
            else 
            {
                result[i][j] = max(result[i - 1][j], result[i][j - 1]);
            }
        }   
    }

    return result[n][n];

}

int main()
{      
    string str1 = "agbcba";
    int n = str1.length();
    cout<<LPS(str1, n);
    return 0;
}