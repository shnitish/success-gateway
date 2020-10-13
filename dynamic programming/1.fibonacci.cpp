#include <iostream>
#include <vector>

using namespace std;

int fibo(int n, vector <int> arr)
{	
	if(n == 0 || n == 1)
		return n;

	if(arr[n] != 0)
		return arr[n];

	int fibo1 = fibo(n - 1, arr);
	int fibo2 = fibo(n - 2, arr);

	int fibon = fibo1 + fibo2;

	arr.push_back(fibon);

	return fibon;
}	

int main()
{	
	int n;
	cin>>n;
	vector <int> arr(n + 1);
	cout<<fibo(n, arr);
	return 0;
}