/*
Given a list of unsorted integers,arr , find the pair of elements that have the smallest absolute difference between them. 
If there are multiple pairs, find them all.

Sample input

10
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 

Sample Output 0

-20 30

Explanation 0
(30) - (-20) = 50, which is the smallest difference.

Sample Input 2

4
5 4 3 2
Sample Output 2

2 3 3 4 4 5
Explanation 2
Here, the minimum difference will be 1. Valid pairs are (2, 3), (3, 4), and (4, 5). 
We print the elements of each pair, space-separated on a single line.

*/

#include <bits/stdc++.h>
#define INF 1000000007

using namespace std;

void pair_diff(int arr[], int n)
{    
     int min = INF;
    for (int i = 0; i < n; ++i)
    {
        int temp = abs(arr[i+1] - arr[i]);
        if (min  > temp)
        {
            min = abs(temp);
        }
    }
    for(int i = 0; i<n; i++)
    {    if (abs(arr[i+1] - arr[i]) == min)
        {
            cout<<arr[i]<<" "<<arr[i + 1]<<" ";
        }
        
    }
}    

int main()
{
    int n;
    cin>>n;
    int arr[100000];
    for (int i = 0; i < n; ++i)
     {
         cin>>arr[i];
     } 
    sort(arr, arr + n);
    pair_diff(arr, n);
    return 0;
}
