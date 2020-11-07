#include <bits/stdc++.h>

using namespace std;

void printNegative(vector <int> arr, int k)
{   
    int i = 0;
    int j = 0;
    int n = arr.size();  
    vector <int> result;

    while (j < n)
    {   
        queue <int> q;

        if(arr[j] < 0)
            q.push(arr[j]);

        if(j - i + 1 < k)
            j++;
        
        else if(j - i + 1 == k)
        {
           if(q.size() == 0)    
              result.push_back(0);
        
           else 
           {    
                result.push_back(q.front()); 
                if(arr[i] == q.front())
                {
                    q.pop();   
                }
           }
           i++;
           j++;
        }
    }
    for(auto x: result)
    {
        cout<<x<<" ";
    }

}

int main()
{   
    vector <int> arr = {12, -1, -7, 8, 15, 30, 16, 28};
    int k = 3;
    printNegative(arr, k);
    return 0;
}