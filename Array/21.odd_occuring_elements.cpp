/*
Make a unordereed map and increment count of each element of array in the map.
return the element with count 1

This program can be modified to check for duplicates

TC = O(n)   Using hashing but SC = O(n) for using extra space.
TC = O(n)   Using XOR but SC = O(1) for not using extra space.
*/


#include <iostream>
#include <unordered_map>

using namespace std;
	
// Best approach to keep count of every element occuring odd times in a array is hashing.

// int unique(int arr[], int size)
// {
// 	unordered_map <int, int> u;
// 	for (int i = 0; i < size; ++i)
// 	{
// 		u[arr[i]]++;
// 	}

// 	for (auto x: u)
// 	{
// 		if (x.second %2 != 0)           // Change condition to check for duplicate elements(greater than 1 )
// 		{
// 			cout<<x.first<<" ";
// 		}
// 	}
// 	return 0;
// }

// OPtimal Approach: If array has only single element which is occuring odd times.
int XOR(int arr[], int size)
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		res = res ^ arr[i];
	}
	return res;
}

int main()
{	
	int size, arr[] = {6, 2, 5,5, 2, 2,2, 6, 6 };
	size = sizeof(arr)/sizeof(arr[0]);
	// unique(arr, size);
	cout<<XOR(arr, size);
	return 0;
}


