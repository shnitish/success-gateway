#include <iostream>
#include <limits.h>

using namespace std;

int coinChange(int val, int coin[], int n)
{
	int result[n + 1][val + 1];

	// To fill the 0th row with infinity
	for(int i = 1; i <= val; i++)
	{
		result[0][i] = INT_MAX - 1;
	}

	// To fill the 0th column with zero
	for(int i = 0; i <= n; i++)
	{
		result[i][0] = 0;
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= val; ++j)
		{	
			// // if coin value is less than j then find min of (previous value of same coloumn, value at same row - cur coin value + 1)
			if(coin[i - 1] <= j)
				result[i][j] = min(result[i - 1][j] , result[i][j - coin[i - 1]] + 1);
				
			// IF not, then copy the previous value from same coloumn
			else
				result[i][j] = result[i - 1][j];
		}
	}

	return result[n][val];
}

int main()
{	
	int coin[] = {9, 6, 5, 1};

	int val = 11;
	int n =4;
	cout<<coinChange(val, coin, n);
	return 0;
}