#include <iostream>
#include <unordered_set>

using namespace std;

int pairs_sum(int arr[] , int size, int sum)
{
	unordered_set<int> u;
	for (int i = 0; i < size; ++i)
	{
		int temp = sum - arr[i];
		if (u.find(temp) != u.end())
		{
			cout<<"Pairs are: "<<arr[i]<<" "<<temp<<endl;
		}
		u.insert(arr[i]);
	}
	return 0;
}
int main()
{	
	int size,sum, arr[] = {1, 4, 45, 6, 10, 8};
	cout<<"Enter sum: "; cin>>sum;
	size = sizeof(arr)/sizeof(arr[0]);
	pairs_sum(arr, size, sum);
	return 0;
}