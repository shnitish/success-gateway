/*
You will be given an array of integers and a target value. 
Determine the number of pairs of array elements that have a difference equal to a target value.


The first line contains two space-separated integers n and k, the size of arr and the target value.
The second line contains n space-separated integers of the array arr.

Sample Input
5 2  
1 5 3 4 2  

Sample Output
3

*/

#include <iostream>
#include <unordered_map>

using namespace std;

int pairs(int arr[], int n, int k)
{   
    int count = 0;

    unordered_map <int, int> m;

    for(int i=0; i<n; i++)
    {
      m[arr[i]];
    }

    for (int i = 0; i < n; ++i)
    {
        int temp = arr[i] + k;

        if (m.find(temp) != m.end())
        {
            count++;
        }

    }
    return count;

}
int main()
{   
    int n, k;
    cin>>n;
    cin>>k;
    int arr[1000000];      // Just increase the size of the input array to avoid segmentation fault.
    
    for(int i=0; i< n; ++i)
    {
        cin>>arr[i];
    }
    
    cout<<pairs(arr, n, k);
   return 0;
}

