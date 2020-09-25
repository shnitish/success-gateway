/*
1) Initialize the minrproduct maxprduct and answer to arr[0] element.
2) Now update the choice1,2 by multiplying the minprod and maxprod with the arr[0+1]th element.
3) Now for arr[0+1] element fin the minprod and maxprod till now by taking min of arr[0+1] element and the min
from choice 1 and 2 and do same with maxproduct.
4) update the answer by taking max of maxprod and the current element which is arr[0+1].
5) Return ans.

TC = O(n)
SC = O(1)

Approach is similar to kadane algo for max sum subarray.
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] ={-1, -3, -10, 0, 60};
	int size = sizeof(arr)/sizeof(arr[0]);

	int maxproduct = arr[0];
	int minproduct = arr[0];
	int ans = arr[0];

	int choice1, choice2 ;

	for (int i = 1; i < size; ++i)
	{
		choice1 = minproduct * arr[i];
		choice2 = maxproduct * arr[i];	
		minproduct = min(arr[i], min(choice1, choice2));
		maxproduct = max(arr[i], min(choice1, choice2));
		ans = max(arr[i], maxproduct);
	}
	cout<<ans;
	return 0;
}
