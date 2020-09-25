#include <iostream>
#include <algorithm>

using namespace std;

int main()
{	
	int k, size, largest, smallest;
	cin>>k;
	cin>>size;
	int *arr = new int(size);
	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}

	cout<<'\n';

	sort(arr, arr + size);

	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"largest: "<<arr[k - 1]<<endl;
	cout<<"smallest: "<<arr[size - k];

	return 0;
}