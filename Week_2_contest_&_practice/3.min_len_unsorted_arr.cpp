/*
Find the indexes of the unsorted subarray on which after sorting, sorts the whole array.

TC: O(N)

step 1: From left find the index in which the value just starts decreasing.
step 2: From right find a index from which the value just starts increasing.
step 3: Find min and max element in the indexes range

*/

#include <iostream>

using namespace std;

int main()
{			 //	 0	1	2	3	4	5 	6	7	8	9	10
	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(arr)/sizeof(arr[0]);
	int left, right, minm, maxm;

	// To find the left position where the values start decreasing
	for ( left = 0; left < n - 1; ++left)
	{
		if (arr[left+1] < arr[left])
			break;
	}

	// To find the value right where value starts increasing
	for ( right = n - 1; right >= left; --right)
	{
		if (arr[right] < arr[right - 1])
			break;
	}

	// find min and max element in the subarray from arr[left] to arr[right] 
	minm = arr[left];
	maxm = arr[left];
	for (int i = left + 1; i <= right ; ++i)
	{
		if (arr[i] > maxm)
			maxm = arr[i];

		if (arr[i] < minm)
			minm = arr[i];
	}


	// Find a value from 0 to arr[left] which is greater than
	// the minm value found above and change the left index pointer.
	for (int i = 0; i < left; ++i)
	{
		if (arr[i] > minm)
		{
			left = i;
		}
	}

	// Find a value from right index to the enc which is smaller than
	// the current maxm value found above and shift the right index pointer
	for (int i = n - 1; i > right; --i)
	{
		if (arr[i] < maxm)
		{
			right = i;
		}
	}

	// Print both indexes of the subarray
	cout<<left<<" "<<right;
	return 0;
}