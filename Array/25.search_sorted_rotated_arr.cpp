#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int l, int h, int key)
{	
	int mid = l +(h - l)/2;

	if (l > h)
	{
		return -1;
	}
	if (arr[mid] == key)
	{
		return mid;
	}

	if (arr[l] <= arr[mid])
	{
		if (key >= arr[l] && key <= arr[mid])
		{
			return search(arr, l, mid - 1, key);
		}

		return search(arr, mid + 1,h ,key);
	}

	else
	{
		if (key >= arr[mid] && key <= arr[h])
		{
			return search(arr, mid + 1, h, key);
		}

		return search(arr, l, mid - 1, key);
		}
}
int main()
{	
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = 9;
	cout<<search(arr, 0, n - 1, 7);
	return 0;
}