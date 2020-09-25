#include <iostream>

using namespace std;

int equilibrium(int arr[], int n)
{
	int sum=0, left_sum, i;
	
		for (int i = 0; i < n; ++i)
			sum += arr[i];

		for (int i = 0; i < n; ++i)
		{
			sum -= arr[i];

			if(sum == left_sum)
			{
				return i;
			}
			left_sum += arr[i];
		}	
	return -1;
}

int main()
{	
	int n , arr[] = {1, 2, 3, 4, 1, 2, 3};
	n = sizeof(arr)/sizeof(arr[0]);
	cout<<equilibrium(arr, n);
	return 0;
}

/* Logic

1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
    a)  Update sum to get the right sum.  
           sum = sum - arr[i] 
       // sum is now right sum
    b) If leftsum is equal to sum, then return current index. 
       // update leftsum for next iteration.
    c) leftsum = leftsum + arr[i]
4) return -1 
// If we come out of loop without returning then
// there is no equilibrium index
*/