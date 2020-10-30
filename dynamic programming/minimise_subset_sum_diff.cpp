/*
https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

Minimise abs(sum(s1) - sum(s2))
Now,

sum(s1) + sum(s2) = totalSum(range)
sum(s2) = range - sum(s1)
so,

s2 - s1 will be
range - s1 - s1        

       ------------
min = |range - 2s1 |   -->eq 1  ( considering s1 < s2 )
       ------------

Perform tabulation to find target sum subset,
find the true values int the range (0, sum/2) and first true value from right to left is the minimised value
*/

#include <iostream>
#include <vector>

using namespace std;

int minimise(vector <int> arr)
{
    int n = arr.size(); 
    int range = 0;

    for(auto x: arr)
        range += x;

    bool result[n + 1][range + 1];

    // target sum subset variation
    for(int i = 1; i <= range; i++)
        result[0][i] = false;
    
    for(int i = 0; i <=n; i++)
        result[i][0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= range; j++)
        {
            if(arr[i - 1] > j)
                result[i][j] = result[i - 1][j];

            else    
                result[i][j] = result[i - 1][j] || result[i - 1][j - arr[i - 1]];
        }
    }

    int mn = INT8_MAX;
    vector <int> values;

    for(int i = range/2; i >= 0; i--)
    {
        if(result[n][i] == true)
           values.push_back(i);
    }

    for(auto x: values)
        mn = min(mn, range - 2*x); // from eq 1 above

    return mn;
}

int main()
{   
    vector <int> arr = {1, 2, 7};
    cout<<minimise(arr);
    return 0;
}