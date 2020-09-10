/*

Kadane algo variation to find the max sum in a continuous and non continuous subarray.
easy to implement.

We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

all nonempty subarrays.
all nonempty subsequences.
Print the two values as space-separated integers on one line.

Sample Input 0

2
4
1 2 3 4
6
2 -1 2 3 4 -5

Sample Output 0

10 10
10 11

*/

#include <bits/stdc++.h>

using namespace std;

void maxsubArray(vector <int> arr, int n)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	int subsequence_sum = 0;

	for (int i = 0; i < n; ++i)
	{
		max_ending_here += arr[i];

		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;

		if (arr[i] > 0)
			subsequence_sum += arr[i];
	}

	if (max_so_far == 0 && subsequence_sum == 0)
	{
		cout<<-1<<" "<<-1;
	}
	else
		cout<<max_so_far<<" "<<subsequence_sum;
}

int main()
{	
	vector <int> arr = {-10};
	int n = arr.size();
	maxsubArray(arr, n);
	return 0;
}