/* 
https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/

Count all possible paths starting from (0,0) to (R, C) only moving:
1) One step right
2) One step down

if moving diagonally is also possible then
just add the diagonal element(result[i - 1][j - 1]) in the result itself
*/
#include <iostream>
#define R 4
#define C 4

using namespace std;

int totPaths(int arr[R][C])
{   
    int result[R][C];

    for(int i = 1; i < C; i++)
        result[0][i] = 1;

    for(int i = 0; i < R; i++)
        result[i][0] = 1;

    for(int i = 1; i < R; i ++)
    {
        for(int j = 1; j < C; j++)
        {        
            result[i][j] = result[i][j - 1] + result[i - 1][j];
        }
    }
    return result[R - 1][C - 1];
}

int main()
{   
    int arr[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout<<totPaths(arr);
    return 0;
}