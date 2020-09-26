#include <bits/stdc++.h>
#define INF 1000000007

using namespace std;

void pair_diff(int arr[], int n)
{	
 	int min = INF;
	for (int i = 0; i < n; ++i)
	{
		int temp = abs(arr[i+1] - arr[i]);
		if (min  > temp)
		{
			min = abs(temp);
		}
	}
	for(int i = 0; i<n; i++)
	{	if (abs(arr[i+1] - arr[i]) == min)
		{
			cout<<arr[i]<<" "<<arr[i + 1]<<" ";
		}
		
	}
}	

int main()
{
	int n;
	cin>>n;
	int arr[100000];
	for (int i = 0; i < n; ++i)
	 {
	 	cin>>arr[i];
	 } 
	sort(arr, arr + n);
	pair_diff(arr, n);
	return 0;
}
