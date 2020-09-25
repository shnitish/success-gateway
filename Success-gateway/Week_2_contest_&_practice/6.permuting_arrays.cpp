/*
Given two arrays of equal size n and an integer k. 
The task is to permute both arrays such that sum of their corresponding element is greater 
than or equal to k i.e a[i] + b[i] >= k. The task is print “Yes” if any such permutation exists, 
otherwise print “No”.
Sample Input

2

3 10
2 1 3
7 8 9

4 5
1 2 2 1
3 3 3 4

Sample Output

YES
NO

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin>>t;
    
    while(t--)
    {
        cin>> n >> k;
        bool flag = true;
        
        // define vectors
        vector <int> arr(n);
        vector <int> brr(n);
            
        // vector inputs
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        // vector inputs
        for(int i = 0; i<n; i++)
        {
            cin>>brr[i];
        }
        
        //sort first vector in ascending order
        sort(arr.begin(), arr.end());
        
        // sort second vector in descending order
        sort(brr.begin(), brr.end(), greater<int>());

        // check the sum values of vector elements less than k
        // if yes then break and print "NO".
        for(int i = 0; i < n; i++)
        {
            if(arr[i] + brr[i] < k)
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}