/*
https://www.geeksforgeeks.org/coin-change-dp-7/
*/

#include <iostream>
#include <limits.h>

using namespace std;

int coinChange(int val, int coin[], int n)
{
	int result[n + 1][val + 1];

	// initialise first row to 0
	for(int i = 1; i <= val; i++)
	{
		result[0][i] = 0;
	}

	// initialise first coloumn to 1
	for(int i = 0; i <= n; i++)
	{
		result[i][0] = 1;
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= val; ++j)
		{	
			// if coint value is less than j, then simply add the value at above row of same col
			// with the value at j minus coin value of same row
			if(coin[i - 1] <= j)
				result[i][j] = result[i - 1][j] + result[i][j - coin[i - 1]];
			
			// if not then simply copy the value at above row of same coloumn
			else
				result[i][j] = result[i - 1][j];
		}
	}

	return result[n][val];
}

int main()
{	
	int coin[] = {1, 2, 4};

	int val = 7;
	int n = 3;
	cout<<coinChange(val, coin, n);
	return 0;
}