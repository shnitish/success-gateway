/*
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

take i = 1;
for n elements there are (n-1) number of matrices
and the dimensions are given in the array.

		0	1	2	3	4
arr = [40, 20, 30, 10, 30]
			i         	j

dimension of Ai is such that arr[i - 1] * arr[i];
and so on for other 3 matrices



*/


#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

int result[1001][1001];

int MCM(int arr[], int n, int i, int j)
{	
	
	// recursion base condition
	if( i >= j)  
		return 0;

	int min_ = INT_MAX;

	// memoization: if the value in the matrix is not -1				
	// then it is sure that it is updated in the earlier call
	// so return this value and recur again for further calls
	if(result[i][j] != -1)
		return result[i][j];

	for(int k = i; k < j; k++)	// k is the break point for the array 
	{	
		int leftCost = MCM(arr, n, i, k); 	// cost from i to k 
		int rightCost = MCM(arr, n, k + 1, j); // cost from k + 1 to j
		int mulCost = (arr[i - 1] * arr[k] * arr[j]); // cost of multiplying matrices 

		int totCost = leftCost + rightCost + mulCost; // total cost

		if(totCost < min_)
			min_ = totCost;
	}

	result [i][j] = min_;

	return result[i][j];
}

int main()
{	
	int arr[] = {40, 20, 30, 10, 30};
	int n = sizeof(arr)/sizeof(arr[0]);
	memset(result, -1, sizeof(result));

	cout<<MCM(arr, n, 1, n - 1);
	return 0;
}