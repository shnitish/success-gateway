/*
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

#include<iostream>
#include <string>

using namespace std;

int LCS(string str1, string str2, int m, int n)
{
	int result[m + 1][n  + 1];

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				result[i][j] = 0;

			else if(str1[i - 1] == str2[j - 1])
				result[i][j] = 1 + result[i - 1][j - 1];

			else
				result[i][j] = max(result[i - 1][j], result[i][j - 1]);
		}
	}

	return result[m][n];
}

int main()
{	
	string str1 = "abcdaf";
	string str2 = "acbcf";
	int m = str1.length();
	int n = str2.length();

	cout<<LCS(str1, str2, m, n);
	return 0;
}