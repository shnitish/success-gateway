/*
https://www.geeksforgeeks.org/min-cost-path-dp-6/

Find the minimum cost path from arr[0][0] to arr[R - 1][C - 1]
moving only
    1) One step down
    2) One step right
*/

#include <iostream>
#include <vector>

using namespace std;

int minCost(vector <vector<int>> arr)
{
    int R = arr.size();
    int C = arr[0].size();

    int result[R][C];
    result[0][0] = arr[0][0];

    // Initialise first row
    for(int i = 1; i < C; i++)
    {
        result[0][i] = result[0][i - 1] + arr[0][i];
    }

    // Initialise first coloumn
    for(int i = 1; i < R; i++)
    {
        result[i][0] = result[i - 1][0] + arr[i][0];
    }

    // fill remaining slots
    for(int i = 1; i < R; i++)
    {
        for(int j = 1; j < C; j++)
        {
            result[i][j] = min(result[i - 1][j], result[i][j - 1]) + arr[i][j];
        }                       // top value     //left value      //curr val in orignal matrix            
    }

    // PRINT MATRIX
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<'\n';
    }

    int i = R - 1;
    int j = C - 1;

    // print min cost path of the matrix
    cout<<"Path: ";
    while(i >= 0 && j > 0)
    {
        if(result[i][ j - 1] < result[i - 1][j])
        {
            cout<<arr[i][j]<<" ";
            j--;
            cout<<arr[i][j]<<" ";
        }
        else
            i--;
        
    }
    cout<<'\n';

    // min cost
    return result[R - 1][C - 1];
}

int main()
{   
    vector <vector <int>> arr = {{1, 2, 8, 10}, 
                                 {3, 4, 1, 9}, 
                                 {5, 6, 2, 3}};

    cout<<minCost(arr);
    return 0;
}