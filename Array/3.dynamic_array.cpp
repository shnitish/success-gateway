#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num, size, max, min, n;
	int arr[size];

	cin>>size;

	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+size);

	for(int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	n = sizeof(arr) / sizeof(arr[0]);
	cout<<'\n';
	cout<<arr[0]<<endl;
	cout<<arr[n - 1]<<endl;

	// max = arr[size];
	// min = arr[0];
	// cout<<arr[0]<<endl;
	return 0;
}