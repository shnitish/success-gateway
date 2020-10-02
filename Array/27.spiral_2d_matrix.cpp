/*
Print spiral matrix in counter clockwise direction
TC = O( M * N)

MinR is the position of the first element in first row					
MinC is the position of the first element in first coloumn
MaxR is the position of the first element in last row
MaxC is the position of the last element in first row

Logic:
Step 1) Traverse the outer box of the matrix first.
step 2) Traverse the inner box.
*/

#include <iostream>

using namespace std;

void spiralprint(int arr[4][4], int R, int C)
{
	int minR = 0;
	int minC = 0;
	int maxR = R - 1;
	int maxC = C - 1;

	int n = R * C;
	int count = 0;

	while(count < n)
	{	
		// left wall
		for (int i = minR; i <= maxR && count < n; ++i)
		{
			cout<<arr[i][minC]<<" ";
			count++;
		}
		minC++;

		// bottom wall
		for (int i = minC; i <= maxC && count < n; ++i)
		{
			cout<<arr[maxR][i]<<" ";
			count++;
		}	
		maxR--;

		// right waall
		for (int i = maxR; i >= minR && count < n; --i)
		{
			cout<<arr[i][maxC]<<" ";
			count++;
		}
		maxC--;

		// top wall
		for (int i = maxC; i >= minC && count < n; --i)
		{
			cout<<arr[minR][i]<<" ";
			count++;
		}
		minR++;
	}
}

int main()
{
	int R = 4;
	int C = 4;
	int arr[4][4] = {
					 {1, 2,  3,  4}, 
					 {5, 6,  7,  8}, 
					 {9, 10, 11, 12},
					 {13,14, 15, 16}};
	spiralprint(arr, R, C);
	cout<<'\n';
	return 0;
}