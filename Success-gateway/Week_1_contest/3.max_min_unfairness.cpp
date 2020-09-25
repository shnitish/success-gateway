/*
You will be given a list of integers,arr , and a single integer k. You must create an array of length k from elements of 
 arr such that its unfairness is minimized. Call that array subarr. Unfairness of an array is calculated as

 max(subarr) - min(subarr)

Sample Input 0

7
3
10
100
300
200
1000
20
30

Sample Output 0

20

Explanation 0

Here k =3 selecting the 3 integers 10, 20, 30 unfairness equals

max(10,20,30) - min(10,20,30) = 30 - 10 = 20
*/


#include <bits/stdc++.h>

using namespace std;

int maxMin(int arr[], int n, int k)
{
	sort(arr, arr + n);
	// int n = arr.size();
	int ans = INT_MAX;

	for(int i = 0; i + k - 1 < n; ++i)
	{
		ans = min(ans, arr[i + k - 1] - arr[i]);
	}

	return ans;
}

int main()
{	
	int n;
	int k;
	cin>>n;
	cin>>k;
	int arr[1000000];

	for (int i = 0; i < n; ++i)
	{	
		cin>>arr[i];
		// arr.push_back(i);
	}

	cout<<maxMin(arr, n, k);
	return 0;
}