#include <bits/stdc++.h>

using namespace std;

void rotate(vector <vector<int> > mat)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(mat[i][j], mat[j][i]);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		reverse(mat[i].begin(), mat[i].end());
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}

int main()
{	
	vector <vector <int> > mat = {{1,2,3}, {4,5,6}, {7,8,9}};

	rotate(mat);
	return 0;
}