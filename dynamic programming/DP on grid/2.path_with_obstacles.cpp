/*
Given a boolean matrix with boolean values
Find unique paths in grid from arr[3][0] to arr[0][3] 
moving only:
    1) One step right   | 1) [0] -> No obstacles 
    2) One step up      | 2) [1] -> Obstacle

*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int totPaths(vector<vector<bool>> arr)
{   
    int R = arr.size();
    int C = arr[0].size();

    // Checking start and end points is an obtacle or not
    if(arr[R - 1][0] == 1 || arr[0][C - 1] == 1)
        return -1;

    int result[R][C];
    memset(result, 0, sizeof(result));

    // if starting is not an obstacle then set 1 in the result matrix
    if(arr[R - 1][0] == 0)
        result[R - 1][0] = 1;

    // initialising the last row
    // if there is an obstacle set it to 0 and continue 
    // copying the previous values to further paths.
    for(int i = 1; i < C; i++)
    {
        if(arr[R - 1][i] == 1)
            result[R - 1][i] = 0;
        
        else 
            result[R - 1][i] = result[R - 1][i - 1];
    }

    // initialising the first coloumn
    for(int i = R - 2; i >= 0; i--)
    {
        if(arr[i][0] == 1)
            result[i][0] = 0;
        
        else 
            result[i][0] = result[i + 1][0];
    }

    // to fill the remaining slots in the matrix 
    for(int i = R - 2; i >= 0; i--)
    {
        for(int j = 1; j < C; j++)
        {
            if(arr[i][j] == 1)
                result[i][j] = 0;
            
            else 
                result[i][j] = result[i][j - 1] + result[i + 1][j];
        }
    }

    // PRINT MATRIX
    for(int i = 0; i < R; i ++)
    {
        for(int j = 0; j < C; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<'\n';
    }

    // return value at end point
    return result[0][C - 1];
}

int main ()
{   
    vector <vector <bool>> arr = {{0, 0, 0}, 
                                  {0, 1, 0}, 
                                  {0, 0, 0}};

    cout<<totPaths(arr);

    return 0;
}