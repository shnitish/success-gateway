/*
Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Method 1: Brute force O(n^2), can be optimised using stack upto O(n)

Sample Input

4
4 5 2 25

Sample Output

4 5
5 25
2 25
25 -1

*/
#include <bits/stdc++.h>

using namespace std;

void nextGreater(vector <int> arr, int n)
{		
	

	for (int i = 0; i < n; ++i)
	{	
		int next = -1;
		for(int j = i + 1; j < n; ++j)
			{
				if (arr[i] < arr[j])
				{
					next = arr[j];
					break;
				}

			}
			cout<<arr[i]<<"-->"<<next<<endl;
	}

}

int main()
{	
	// int n;
	// cin>>n;
	vector <int> arr = {4, 5, 2, 25};
	int n = arr.size();
	nextGreater(arr, n);
	return 0;
}