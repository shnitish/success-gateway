/*
1) Find a break point starting from the end.
(break point is the index in the array where upto where the elements values are increasing when started from the end.)

ex:        5      <-- This is the breaking point of { 1, 3, 5 ,4 ,2} gives = {1,4,2,3,5}
         3   4
       1       2 

2) Starting from the second last index check if break point exists and save it in K.
3) Check if break points does'nt exists then just reverse the array.
4) else find a element which is just greater than [k - 1]th element and perform swap it.
5) Finally reverse the elements from break point to the last.

TC; O(n)
SC: O(1)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int permutation( int arr[], int size)
{
	int k, l;

	for(k = size - 2; k >=0; k--)  //assuming that break point will be present before the 2nd last element.
	{
		if (arr[k] < arr[k + 1])
		{
			break;
		}
	}

	if (k < 0)
	{
		reverse(arr, arr + size);
	}

	else
	{
		for( l = size - 1; l >= 0; l--)
		{
			if (arr[l] > arr[k])
			{
				break;
			}
		}

		swap(arr[l], arr[k]);
		reverse(arr + k + 1, arr);
	}
return 0;	
}

int main()
{
	int arr[] = {1,2,3};
	int size = 3;
	cout<<permutation(arr, size);
	return 0;
}