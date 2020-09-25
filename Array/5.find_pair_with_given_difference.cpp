#include <iostream>
#include <unordered_set>

using namespace std;

void pair_diff(int arr[], int n, int diff)
{
	unordered_set<int> map;
	for (int i = 0; i < n; ++i)
	{
		int temp = arr[i] - diff;
		if (map.find(temp) != map.end())
		{
			cout<<temp<<" "<<arr[i];
		}
		map.insert(arr[i]);
	}
}	

int main()
{
	int n, diff = 78, arr[] = {5, 20, 3, 2, 50, 80};
	n = sizeof(arr)/sizeof(arr[0]);

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	pair_diff(arr, n , diff);
	return 0;
}
