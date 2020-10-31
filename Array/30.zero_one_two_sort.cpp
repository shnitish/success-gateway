/*
Sort an array having only 0, 1, 2

Logic: Patitioning same as quick sort
Dutch National Flag algo

TC : O(n)
SC : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

void sortPartition(vector <int> arr)
{
    int i = 0;  // 0 to j - 1 -> 0's area 
    int j = 0;  // j to i - 1 -> 1's area
    int k = arr.size() - 1; // k + 1 to end -> 2's area

    // i to k is unknown 
    // when i crosses k the array is sorted

    while (i <= k)
    {
        if(arr[i] == 1)
        {
            i++;
        }
        
       else if(arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }

        else
        {
            swap(arr[i], arr[k]);
            k--;
        }
    }

     for(auto x: arr)
        cout<<x<<" ";
    
}

int main()
{   
    vector <int> arr = {1, 1, 2, 2, 0, 1, 2, 2, 1, 0, 1, 2, 0, 2, 1};
    sortPartition(arr);
    return 0;
}