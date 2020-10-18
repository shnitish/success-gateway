/*
https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
*/

#include <iostream>

using namespace std;

int countSubset(int arr[], int n, int sum)
{
	int result[n + 1][sum + 1];

	for(int i = 1; i <= sum; i++)
		result[0][i] = 0;

	for(int i = 0; i <= n; i++)
		result[i][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= sum; ++j)
		{
			if( arr[i - 1] > j)
				result[i][j] = result[i - 1][j];

			else
				result[i][j] = result[i - 1][j] + result[i - 1][j - arr[i - 1]]; // just change or operator to add operator to count
		}																		//	the subsets with a given sum
	}

	return result[n][sum];
}

int main()
{	
	int arr[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<countSubset(arr, n, sum);
	return 0;
}