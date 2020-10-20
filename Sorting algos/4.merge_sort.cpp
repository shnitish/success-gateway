/*
TC = O(nlogn)
SC = O(n)
*/

#include <iostream>

using namespace std;


void merge(int arr[], int low, int mid, int high)
{	
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int leftSorted[n1];
	int rightSorted[n2];


	for(int i = 0; i < n1; i++)
	{
		leftSorted[i] = arr[low + i];
	}

	for (int i = 0; i < n2; ++i)
	{
		rightSorted[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = low;

	while(i < n1 && j < n2)
	{
		if(leftSorted[i] <= rightSorted[j])
		{
			arr[k] = leftSorted[i];
			i++;
		}
		else
		{
			arr[k] = rightSorted[j];
			j++;
		}
		k++;
	} 

	while(i < n1)
	{
		arr[k] = leftSorted[i];
			i++;
			k++;
	}

	while(j < n2)
	{
		arr[k] = rightSorted[j];
			j++;
			k++;
	}
}

void mergeSort(int arr[], int n, int low, int high)
{	
	if(low < high)
	{

	int mid = (low + high)/2;
	mergeSort(arr, n, low, mid);
	mergeSort(arr, n, mid + 1, high);
	merge(arr, low, mid, high);

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
	int arr[] = {7,4,1,3,6,8,2,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergeSort(arr,n, 0, n - 1);
	print(arr, n);
	return 0; 
}