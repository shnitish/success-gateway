/*
Leaders in an array

Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side. 
And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, 
leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.

*Logic is to traverse the array from end*

Sample Input 0

6
3 12 34 2 0 -1

Sample Output 0

34 2 0 -1


*/

#include <bits/stdc++.h>

using namespace std;

void leader(vector <int> arr, int n )
{	
	vector <int> b;

	int maxm = arr[n - 1];
	b.push_back(maxm);
	// cout<<maxm<<" ";

	for (int i = n - 2; i >= 0 ; --i)
	{
		if (arr[i] > maxm)
		{
			// cout<<arr[i]<<" ";
			maxm = arr[i];
			b.push_back(maxm);
		}
	}

	reverse(b.begin(), b.end()); // reverse is done to print the values from end because they are
								 // stored in the reverse order as reading from end.
	
	for (auto x: b)
	{
		cout<<x<<" ";
	}
}
int main()

{	
	vector <int> arr = {3, 12, 34, 2, 0, -1};
	int n = arr.size();
	leader(arr, n);
	return 0;
}