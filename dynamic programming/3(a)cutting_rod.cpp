/*
Knapsack variation

*/

#include <iostream>

using namespace std;

int maxProfit(int profit[], int n, int len)
{	
	// Array that keeps the record for the length of the rods 1,2,3.... and 
	//profit array keeps their corresponding profit to it
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	// Result array that will store all possibilties
	int result[n + 1][len + 1];

	for(int i = 1; i <= len; ++i)
		result[0][i] = 0;

	for (int i = 0; i <= n; ++i)
		result[i][0] = 0;


	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			if(arr[i - 1] > j)
				result[i][j] = result[i - 1][j];

			else
				result[i][j] = max(result[i - 1][j], profit[i - 1] + result[i][j - arr[i - 1]]);
		}
	}
	
	return result[n][len];
}

int main()
{		
		// profits at length 1,2,3...
	int profit[] = {2 ,5, 8, 10};
	int n = sizeof(profit)/sizeof(profit[0]);
	int len = 5;
	cout<<maxProfit(profit, n, len);
	return 0;
}