/*
https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

Peak element = Element which is greater from it's both left and right element.

Edge cases and conditions for a peak element

1) If mid is first element so we check mid with only with it's right element 
and return which of them was greater.
2) If mid is the last element so we check mid with only it's left element
and return which of them was greater.
*/

#include <iostream>
#include <vector>

using namespace std;

int searchPeak(vector <int> arr)
{
    int n = arr.size();
    int start = 0;
    int end =  n - 1;

    // binary search variation
    while (start <= end)
    {
        int mid = start + (end - start)/2;

        if(mid > 0 && mid < n - 1)
        {
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return arr[mid];
            
            else if(arr[mid - 1] > arr[mid])
                end = mid - 1;
            
            else 
                start = mid + 1;   
        }

        // edge cases 
        else if(mid == 0)
        {
            if(arr[mid] > arr[mid + 1])
                return arr[mid];
            
            else 
                return arr[mid + 1];
        }

        // edge case
        else if(mid == arr[n - 1])
        {
            if(arr[n - 1] > arr[n - 2])
                return arr[n - 1];
            
            else
                return arr[n - 2];
        }
    }

    //else 
    return -1;
   
}

int main()
{   
    vector <int> arr = {10, 20, 15, 2, 23, 90, 67};
    cout<<searchPeak(arr);
    return 0;
}