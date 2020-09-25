/*
LInk: https://www.techiedelight.com/inplace-merge-two-sorted-arrays/
*/

#include <iostream>
#include <algorithm>

using namespace std;

void merge_array(int arr1[], int arr2[], int size1, int size2)
{
	for (int i = 0; i < size1; ++i)
	{	
		if (arr1[i] > arr2[0])
		{
			swap(arr1[i], arr2[0]);
		}
		int first = arr2[0];
		for (int j = 1; j < size2; ++j)
		{
			sort(arr2, arr2+size2);
		}
}
}
int main()
{	
	int arr1[] = {1, 5, 9, 10, 15, 20};
	int arr2[] = {2, 3, 8, 13};

	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int n = size1 + size2;
	merge_array(arr1, arr2, size1, size2);

	for (int i = 0; i < size1; ++i)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<'\n';

	for (int i = 0; i < size2; ++i)
	{
		cout<<arr2[i]<<" ";
	}

	return 0;
}