/*
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

Using gap strategy

1) if gap == 0 (arr[1][1], arr[2,][2]) then it means we have only one element and copy as it is.
2) if gap == 1 (arr[1][2], arr[0][1], arr[2][3]) then it means we have two elements so choose the max of them
3) otherwise, 
        if we choose i, then values left are from (i + 1, j),
          if opponent chooses (i + 1) then we are left with (i + 2 to j) and if it chooses
             (j) then we are left with (i + 1 to j - 1) and find min of both

        if we choose j, then values are left with (i to j - 1) 
            if opponent chooses (i) we are left with (i + 1, j - 1) and if it chooses (j - 1)
                 we are left with (i, j - 2) find min of both

finally find max of both the possibilites
*/

#include <iostream>

using namespace std;

int gameStrategy(int arr[], int n)
{
    int result[n + 1][n + 1];

    //gap strategy
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {   
            if(gap == 0)
                result[i][j] = arr[i];

            else if(gap == 1)
                result[i][j] = max(arr[i], arr[j]);
            
            else 
            {
                int val1 = arr[i] + min(result[i + 2][j], result[i + 1][j - 1]);
                int val2 = arr[j] + min(result[i + 1][j - 1], result[i][j - 2]);
                int finVal = max(val1, val2);

                result[i][j] = finVal;
            }
        }
    }

    return result[0][n - 1];
}

int main()
{   
    int arr[] = {20, 30, 2, 2, 2, 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<gameStrategy(arr, n);
    return 0;
}