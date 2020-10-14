/*
https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

TC = O(n^2)
SC = O(n)
*/

#include <iostream>

using namespace std;

int LIS(int arr[], int n)
{
	int result[n];

	int omax = 0;

	for(int i = 0; i < n; i++)
	{		
		int max = 0;

		result[i] = 0;

		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
			{
				if(result[j] > max)
					max = result[j];
			}
		}

		result[i] = max + 1;

		if(result[i] > omax)
			omax = result[i];
	}
	return omax;
}

int main()
{	
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<LIS(arr, n);
	return 0;
}