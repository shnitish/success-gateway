/*

Rotate matrix by 90 degree

Given a two dimensional array of size N X N rotate the array by 90 degrees clockwise. 
Note that you should not use another array to perform rotation. To put it in another way, you must rotate the array inplace.

INPUT

2
1 2
3 4

OUTPUT

3 1
4 2

Logic

1. Take transpose.
2. Reverse the rows.

*/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector <vector<int> > mat, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(mat[i][j], mat[j][i]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		reverse(mat[i].begin(), mat[i].end());
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}

int main()
{	
	int n, value;
	cin>>n;

	vector <vector <int> > mat(n , vector <int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>mat[i][j];
		}
	}
	rotate(mat, n);
	return 0;
}