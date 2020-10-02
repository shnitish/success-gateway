/*
Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
Traverse the array from start to end and mid is less than high. (Loop counter is i)
If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
If the element is 1 then update mid = mid + 1
If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the output array.
*/

#include <iostream>

using namespace std;

void sortarray(int arr[], int size)
{
	int low = 0;
	int mid = 0;
	int high = size - 1;

	while(mid <= high)
	{
		switch(arr[mid])
		{
			case 0:
				swap(arr[low], arr[mid]);
				low++;
				mid++;
				break;

			case 1:
				mid++;
				break;

			case 2:
				swap(arr[mid], arr[high]);
				high--;
				break;
		}
	}
}

int main()
{
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	sortarray(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}