/*
Vairiation of longest increasing subsquence

TC = O(n^2)
SC = O(n)
*/

#include <iostream>
#include <limits.h>

using namespace std;

int maxSumSeq(int arr[], int n)
{
	int result[n];
	int omax = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		int max = 0;
		result[i] = 0;

		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
			{	
				// if max is not updated yet then initialize with arr[0]
				if(max == INT_MIN)
					max = arr[i];

				else if( result[j] > max)
					max = result[j];
			}
		}

		// if there is not max sum subsequence present
		// then store the array value itself
		if(max == INT_MIN)
			result[i] = arr[i];

		// else update it
		else 
			result[i] = max + arr[i];

		// overall max sum
		if(result[i] > omax)
			omax = result[i];
	}

	return omax;
}

int main()
{	
	int arr[] = {5, 8, 2, 3, 12, 4, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<maxSumSeq(arr, n);
	return 0;
}