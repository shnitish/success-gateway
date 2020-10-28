/*
https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
*/

#include <iostream>
#define m 6
#define n 5

using namespace std;

int maxSizeSubsquareMat(bool mat[m][n])
{
    int result[m + 1][n + 1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                result[i][j] = 0;

            // if true(1) 
            // then find the min of its neighbouring element and add 1 to it
            // else just store 0 for false(0) value            
            else if (mat[i - 1][j - 1] == 1)
                result[i][j] = 1 + (min(result[i][j - 1], min(result[i - 1][j - 1], result[i - 1][j])));
            
            else 
                result[i][j] = 0;        
        }
    }

    int maxElement = result[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(result[i][j] > maxElement)
                maxElement = result[i][j];
        }
    }

    return maxElement;
}

int main()
{   
    bool mat[m][n] ={
                           {0, 1, 1, 0, 1},  
                           {1, 1, 0, 1, 0},  
                           {0, 1, 1, 1, 0},  
                           {1, 1, 1, 1, 0},  
                           {1, 1, 1, 1, 1},  
                           {0, 0, 0, 0, 0}
                    };

    cout<<maxSizeSubsquareMat(mat);
    return 0;
}