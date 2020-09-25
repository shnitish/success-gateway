/*Efficient Approach: There is an idea if all the elements of the array are positive. If a subarray has sum greater than the given sum then there is no possibility that adding elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.

Algorithm:

Create three variables, l=0, sum = 0
Traverse the array from start to end.
Update the variable sum by adding current element, sum = sum + array[i]
If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
If the sum is equal to given sum, print the subarray and break the loop.*/

#include <iostream>

using namespace std;

int subArraySum(int arr[], int n, int sum)
{
	int curr_sum = arr[0];
	int start = 0;

	for (int i = 0; i < n; ++i)
	{
		while(curr_sum > sum)
		{
			curr_sum -= arr[i];
			start++;
		}

		if (curr_sum == sum)
		{
			cout<<start<<" "<<i - 1;
			return 1;
		}
	
	}
	return 0;
}

int main()
{	
	int arr[] = { 11, 4, 20, 3, 10, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 33; 
    cout<<subArraySum(arr, n, sum);  
	return 0;
}