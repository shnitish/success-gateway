#include <iostream>

using namespace std;

int knapsack(int val, int weight[], int profit[], int n)
{
	int result[n + 1][val + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= val; j++)
		{	
			// Fill 0th row and 0th coloumn with zero
			if(i == 0 || j == 0)
			{
				result[i][j] = 0;
			}

			// if weight value is greater than j, copy previous value of the same coloumn
			else if( weight[i - 1] > j)
				result[i][j] = result[i - 1][j];
			
			// if not then find max of (previous value of the same coloumn, profit value of cur weight + val at (j - weight) coloumn)
			else
				result[i][j] = max(result[i - 1][j], profit[i - 1] + result[i - 1][j - weight[i - 1]]);
		}
	}

	return result[n][val];
}

int main()
{	
	int weight[] = {1, 3, 4, 5};
	int profit[] = {1, 4, 5, 7};

	int val = 7;
	int n =4;
	cout<<knapsack(val, weight, profit, n);
	return 0;
}