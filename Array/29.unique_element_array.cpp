/*
Make a unordereed map and increment count of each element of array in the map.
return the element with count 1

This program can be modified to check for duplicates
*/


#include <iostream>
#include <unordered_map>

using namespace std;

int unique(int arr[], int size)
{
	unordered_map <int, int> u;
	for (int i = 0; i < size; ++i)
	{
		u[arr[i]]++;
	}

	for (auto x: u)
	{
		if (x.second == 1)           // Change condition to check for duplicate elements(greater than 1 )
		{
			cout<<x.first;
		}
	}
	return 0;
}
int main()
{	
	int test, size, arr[] = {6, 2, 5, 2, 2, 6, 6 };
	size = sizeof(arr)/sizeof(arr[0]);
	unique(arr, size);
	return 0;
}