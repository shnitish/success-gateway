/*
1) Find LIS from left and right
2) Then return the sum of max from both lists - 1

TC = O(n^2)
SC = O(n) because we used two auxillary arrays

*/


#include <iostream>

using namespace std;

int longestBitonic(int arr[], int n)
{	

	// To store LIS from left
	int result1[n];

	// to store LIS from right
	int result2[n];

	// overall max LIS from left
	int omax1 = 0; 

	// overall max LIS from right
	int omax2 = 0;

	// find LIS from left
	for(int i = 0; i < n; i++)
	{	
		result1[i] = 0;
		int max1 = 0;

		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
			{
				if(result1[j] > max1)
				{
					max1 = result1[j];
				}
			}
		}
		result1[i] = max1 + 1;
		if(result1[i] > omax1)
			omax1 = result1[i];
	}


	// find LIS from right
	for(int i = n - 1; i >= 0; i--)
	{		
		result2[i] = 0;
		int max2 = 0;
		for(int j = n - 1; j > i; j--)
		{
			if(arr[j] < arr[i])
			{
				if(result2[j] > max2)
					max2 = result2[j];
			}
		}

		result2[i] = max2 + 1;
		if(result2[i] > omax2)
			omax2 = result2[i];
	}

	// take the the first elements of both list as overall max
	// and compare the result with sum of other elements and update for same
	// return omax at the end
	int omax = result1[0] + result2[0] - 1;

	for(int i = 1; i < n; i++)
	{
		if (result1[i] + result2[i] - 1 > omax)
		{
			omax = result1[i] + result2[i] - 1;
		}
	}

	return omax;

}

int main()
{	
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<longestBitonic(arr, n);
	return 0;
}