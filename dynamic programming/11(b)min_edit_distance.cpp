/*
https://www.geeksforgeeks.org/edit-distance-dp-5/

another variation of the LCS problem
*/

#include <iostream>
#include <string>

using namespace std;

int editDistance(string str1, string str2, int m, int n)
{
	int result[m + 1][n + 1];

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{	
			// initialise the frist row of the matrix
			if(i == 0)
				result[i][j] = j;

			// initialise the first col of matrix
			else if( j == 0)
				result[i][j] = i;

			// if the character doesn't matches then find the 	
			// min of the 3 elements (i.e) 
			// 1. left diagonal
			// 2. right diagonal both elements
			// and add 1 to it
			else if(str1[i - 1] != str2[j - 1])
				result[i][j] = 1 + min(result[i][j - 1], min(result[i - 1][j - 1], result[i - 1][j]));

			// if the character matches
			// simply copy the left diagonal element
			else
				result[i][j] = result[i - 1][j - 1];
		}
	}

	return result[m][n];

}

int main()
{	
	string str1 = "bcdefg";
	string str2 = "badfe";

	int m = str1.length();
	int n = str2.length();

	cout<<editDistance(str1, str2, m, n);
	return 0;
}