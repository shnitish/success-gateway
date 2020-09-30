

#include <iostream>

using namespace std;

void pascal(int n)
{
	for (int line = 1; line <= n; ++line)
	{
		int C = 1;
		for(int i = 1; i<= line; ++i)
		{
			cout<< C<<" ";
			C = C * (line - i) / i;
		}
	cout<<'\n';
	}
}
int main()
{	
	int n;
	cin>>n;
	pascal(n);
	return 0;
}