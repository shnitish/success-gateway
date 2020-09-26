#include <bits/stdc++.h>

using namespace std;

void nextGreater(int arr[], int n)
{	
	int *nge = new int(n);

	stack <int> s;

	s.push(arr[n - 1]);
	nge[n - 1] = - 1;

	for (int i = n - 2; i >= 0; --i)
	{
		while(s.size() > 0 && arr[i] >= s.top())
		{
			s.pop();
		}

		if (s.size() == 0)
		{
			nge[i] = -1;
		}

		else
		{
			nge[i] = s.top();
		}

		s.push(arr[i]);
	}

	// print nge 
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" "<<nge[i]<<endl;
	}
}

int main()
{	
	int n;
	cin>>n;
	int arr[10000];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	// int n = sizeof(arr)/sizeof(arr[0]);
	nextGreater(arr, n);
	return 0;
}