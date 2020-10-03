/*
This method is a space optimized version of above method 1. This method uses the first row and first column of the input matrix in place of the auxiliary arrays row[] and col[] of method 1. So what we do is: first take care of first row and column and store the info about these two in two flag variables rowFlag and colFlag. Once we have this info, we can use first row and first column as auxiliary arrays and apply method 1 for submatrix (matrix excluding first row and first column) of size (M-1)*(N-1).

1) Scan the first row and set a variable rowFlag to indicate whether we need to set all 1s in first row or not.
2) Scan the first column and set a variable colFlag to indicate whether we need to set all 1s in first column or not.
3) Use first row and first column as the auxiliary arrays row[] and col[] respectively, consider the matrix as submatrix starting from second row and second column and apply method 1.
4) Finally, using rowFlag and colFlag, update first row and first column if needed.

Time Complexity: O(M*N)
Auxiliary Space: O(1)
*/

#include <iostream>
#define R 3
#define C 3


using namespace std;

int makeZeroes(int mat[R][C])
{
	bool row = false;
	bool col = true;

	for (int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			if (i == 0 && mat[i][j] == 0)
			{
				row = true;
			}

			if (j == 0 && mat[i][j] == 0) 
			{
				col = true;
			}

			if (mat[i][j] == 0)
			{
				mat[i][0] = 0;
				mat[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < R; ++i)
	{
		for(int j = 1; j < C; ++j)
		{
			if (mat[0][j] == 0 || mat[i][0] == 0)
			{
				mat[i][j] = 0;
			}
		}
	}

	if (row == true)
	{
		for (int i = 0; i < C; ++i)
		{
			mat[0][i] == 0;
		}
	}

	if (col == true)
	{
		for (int i = 0; i < C; ++i)
		{
			mat[i][0] == 0;
		}
	}

	return 0;
}

void printMatrix(int mat[R][C])
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout<<mat[i][j];
		}
	cout<<'\n';
	}
}

int main()
{
	int mat[R][C] = { { 1, 1, 1}, 
                	  { 1, 0, 1}, 
					  { 1, 1, 1} }; 
	printMatrix(mat);
	makeZeroes(mat);
	printMatrix(mat);
  
	return 0;
}