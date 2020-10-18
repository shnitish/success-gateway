#include <iostream>

using namespace std;

// check whether wether sum/2 exists or not in the array.
// target sum subset problem
bool isSubsetSum(int arr[], int n, int sum)
{
	bool result[n + 1][sum + 1];

	for(int i = 1; i <= sum; i++)
		result[0][i] = false;

	for(int i = 0; i <= n; i++)
		result[i][0] = true;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(arr[i - 1] > j)
				result[i][j] = result[i - 1][j];
			else
				result[i][j] = result[i - 1][j] || result[i - 1][j - arr[i - 1]];
		}
	}
	return result[n][sum];
}


// if sum is even then there is a possibility of equel sum partition
// so we search the subset in the array equal to sum/2 
// if sum/2 exists then array can be divided into equal sum partition else not
bool isEqualSum(int arr[], int n)
{	
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];

	// if sum is odd return false
	// because it cannot be divided into equal sum partitions.
	if(sum%2 != 0)
		return false;

	else
		{
			return(isSubsetSum(arr, n, sum/2));
		}
}

int main()
{	
	int arr[] = {2,1,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	// int k = 3;
	cout<<isEqualSum(arr, n);
	return 0;
}