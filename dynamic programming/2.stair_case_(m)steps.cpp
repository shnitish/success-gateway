#include <iostream>

using namespace std;


// Method 1
// Varying of n number of steps
int Countways1(int stair, int steps)
{
	int result[stair + 1];

	result[0] = 1;
	result[1] = 1;

	for (int i = 2; i <= stair; ++i)
	{
		result[i] = 0;

		for(int j = 1; j <= steps && j <= i; ++j)
		{
			result[i] += result[i - j];
		}
	}
	return result[stair];
}

//Method 2
// Fixed 3 steps for n number of stairs
int Countways2(int stair)
{
	int result[stair + 1];
	result[0] = 1;

	for (int i = 1; i <= stair; ++i)
	{	
		if(i == 1)
		{
			result[i] = result[i - 1];
		}

		else if( i == 2)
		{
			result[i] = result[i - 1] + result[i - 2];
		}

		else // for i = 1 ([i - 2] and [i - 3] will return negative val so handling the exception above in if statements)
			 // same for i = 2
			result[i] = result[i - 1] + result[i - 2] + result[i - 3];
	}

	return result[stair];
}

int main()
{	
	int stair, steps;
	cin>>stair>>steps;
	cout<<Countways1(stair, steps)<<endl;
	cout<<Countways2(stair);
	return 0;
}