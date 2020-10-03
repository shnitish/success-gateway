/*
1. Take first element as minimal, compare it with next element
if next element is less than current minimal, then update the minimal.
2. Find max profit by taking max of current max and the difference of next element with the minimal value.
3. Return max profit.

TC = O(n)
SC = O(1)

*/


#include <bits/stdc++.h>

using namespace std;

int profit(vector <int> arr)
{
	int minimum = INT_MAX;
	int maxprof = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		minimum = min(minimum, arr[i]);
		maxprof = max(maxprof, arr[i] - minimum);
	}

	return maxprof;
}

int main()
{ 	
	vector <int> arr = {7, 1, 5, 3, 6, 4};
	cout<<profit(arr);
	return 0;
}
