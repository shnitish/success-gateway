/*
1. Comparing adjacent elements
2. Swap, if (j)th element is greater than (j + 1) element
3. This sort the largest element to the last of the array in first pass.
4. For n elements we have to iterate (n-1) times.

TC = O(n^2)
SC = O(1)
*/

#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{	
	int arr[] = {10, 8, 20, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	print(arr, n);
	bubble_sort(arr, n);
	cout<<'\n';
	print(arr, n);
	return 0;
}