/*
https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
*/

#include <iostream>
#include <limits.h>

using namespace std;

int minJumps(int arr[], int n)
{
	int result[n];
	result[0] = 0;

	for(int i = 1; i < n; i++)
	{
		result[i] = INT_MAX;
		for(int j = 0; j < i; j++)
		{
			if(j + arr[j] >= i)
			{
				result[i] = min(result[i], 1 + result[j]);
			}
		}
	}

	return result[n - 1];
}

int main()
{	
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minJumps(arr, n);
	return 0;
}