/*
sum(s1) - sum(s2) = diff         eq 1
sum(s1) + sum(s2) = totalSum     eq 2   Adding both we get
-----------------------------
2 sum(s1) = diff + totalSum
-----------------------------

 -------------------------------
|sum(s1) = (diff + totalSum) / 2|
 ------------------------------=

Then find target sum subset with sum(s1).
(same as count subset with a given sum with variation)

*/

#include <iostream>
#include <vector>

using namespace std;

int subsetCount(vector <int> arr, int diff)
{   
    int n = arr.size();

    // sum of array elements
    int sumArray = 0;
    for(auto x:  arr)
        sumArray += x;
    
    // Acc to eq above
    int set1Sum = (diff + sumArray)/2;

    // tabulation matrix
    int result[n + 1][set1Sum + 1];

    for(int i = 1; i <= set1Sum; i++)
        result[0][i] = 0;
    
    for(int i = 0; i <= n; i++)
        result[i][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= set1Sum; j++)
        {
            if(arr[i - 1] > j)
                result[i][j] = result[i - 1][j];
            
            else 
                result[i][j] = result[i - 1][j] + result[i - 1][j - arr[i - 1]];

        }
    }

    return result[n][set1Sum];
}

int main()
{   
    vector <int> arr = {2, 2, 4, 6};
    int diff = 2;
    cout<<subsetCount(arr, diff);
    return 0;
}