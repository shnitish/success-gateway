/*
https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/

#include<iostream>
#include <string>

using namespace std;

int LCS(string str1, string str2, int m, int n)
{
	int result[m + 1][n  + 1];
	int common_string = 0;

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				result[i][j] = 0;

			else if(str1[i - 1] == str2[j - 1])
			{
				result[i][j] = 1 + result[i - 1][j - 1];
				common_string = max(common_string, result[i][j]);	// Keeps count of the longest common SS till now
			}

			// if character does not matches
			// which means discontinuity in the string and simply store 0 in the matrix
			else
				result[i][j] = 0;
		}
	}

	return common_string;
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