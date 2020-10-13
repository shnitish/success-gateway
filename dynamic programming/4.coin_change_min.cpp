#include <iostream>
#include <limits.h>

using namespace std;

int coinChange(int val, int coin[], int n)
{
	int result[n + 1][val + 1];

	// To fill the 0th row with infinity
	for(int i = 0; i <= val; i++)
	{
		result[0][i] = INT_MAX;
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
			// IF coin value is greater than j then copy the previous value from same coloumn
			if(coin[i - 1] > j)
				result[i][j] = result[i - 1][j];

			// if it is not then find min of (previous value of same coloumn, value at same row - cur coin value + 1)
			else
				result[i][j] = min(result[i - 1][j] , result[i][j - coin[i - 1]] + 1);
		}
	}

	return result[n][val];
}

int main()
{	
	int coin[] = {1, 5, 7, 8};

	int val = 12;
	int n =4;
	cout<<coinChange(val, coin, n);
	return 0;
}