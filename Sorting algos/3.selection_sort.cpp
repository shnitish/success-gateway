/*
1. find minimum element in the array and swap it with arr[0]
2. repeat this for (n + 1) upto (n - 1) elements.

TC = O(n^2)
SC = O(1)
*/

#include <iostream>

using namespace std;

void selection_sort(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min_index = i;

		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		swap(arr[i], arr[min_index]);
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
	selection_sort(arr, n);
	cout<<'\n';
	print(arr, n);
	return 0;
}