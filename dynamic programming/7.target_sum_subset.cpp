/*
https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
*/

#include <iostream>

using namespace std;


bool targetSum(int arr[], int sum, int n)
{
	bool result[n + 1][sum + 1];

	for(int i = 1; i <= sum; i++)
		result[0][i] = false;

	for(int i = 0; i <= n; i++)
		result[i][0] = true;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(arr[i - 1] > j)
				result[i][j] = result[i - 1][j];
				
			else
				result[i][j] =  result[i - 1][j] || result[i - 1][j - arr[i - 1]];
				
		}
	}

	return result[n][sum];
}

int main()
{	
	int arr[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(arr)/sizeof(arr[0]);

	if(targetSum(arr, sum, n))
	{
		cout<<"Targer sum found";
	}
	else
		cout<<"Target sum not found";
	return 0;
}