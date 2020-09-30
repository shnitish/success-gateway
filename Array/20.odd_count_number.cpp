#include <bits/stdc++.h>

using namespace std;

int odd(int arr[], int n)
{   
    unordered_map <int, int> m;
    
    for(int i = 0; i< n; i++)
    {
        m[arr[i]]++;
    }
    for(auto x: m)
    {
        if(x.second % 2 != 0)
        {
            cout<<x.first;
        }
    }
    return 0;
}
int main() 
{
    int k, n;
    cin>>k;
    n = (2 * k + 1) ;
    int arr[100000];
    
    for(int i = 0; i < n ; i++)
    {
        cin>>arr[i];
    }
    odd(arr, n);
    return 0;
}