/*
Insertion sort is optimal for small arrays and performs better than all other sorting algos
Whereas if input array is large then use quick or merge sort because they work on a certain threshold.

1) Consider 1st element as sorted and compare the next element with it.
2) this will sort the first two elements and compare next element finding it's correct position in the sortec part.

TC = O(n^2) (when array is reverse sorted)
SC = O(1)
*/

#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		while(arr[j] > key && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
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
	insertion_sort(arr, n);
	cout<<'\n';
	print(arr, n);
	return 0;
}