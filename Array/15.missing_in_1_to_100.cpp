#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int arr[101], brr[101];

	for (int i = 1; i < 101; ++i)
	{
		cin>>brr[i];
	}

	long long int sum1 = (101*(101 + 1))/2;
	cout<<sum1<<endl;
	long long int  sum2 = 0;

	for (long long int i = 1; i < 101; ++i)
	{
		sum2 += brr[i];
	}
	cout<<sum2<<endl;
	long long int res = sum1 - sum2;
	cout<<res<<endl;
	return 0;
}