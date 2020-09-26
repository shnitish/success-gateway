#include <iostream>
#include<cstring>



using namespace std;

void segment(int arr[], int n)
{
	int temp[n];
	int j = 0;

	// store -ve elements in temp array
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0)
		{
			temp[j++] = arr[i];
		}
	}

	// store +ve elements in temp array
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] >= 0)
		{
			temp[j++] = arr[i];
		}
	}

	memcpy(arr, temp, sizeof(temp));

}
int main()
{	
	int n;
	int arr[] = {1 ,-1 ,-3 , -2, 7, 5, 11, 6};
	n = sizeof(arr)/sizeof(arr[0]);
	segment(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}