/*
https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

if(array is LEFT rotated then no_of_rotations is equal to (length - index_of_min_element)%length)        
if(  array is RIGHT rotated then no_of_rotations = index_of _min_element)

***Not applicable for repeated values***

*/

#include <iostream>
#include <vector>

using namespace std;

int rotIndex(vector <int> arr, int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {   
        if(arr[start] <= arr[end])
            return start;

        int mid = start + (end - start)/2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if(arr[mid] <= arr[prev])
        { 
            return mid;
        }
        
        else if (arr[start] <= arr[mid])
            start = mid + 1;
        
        else if(arr[mid] <= arr[end])
            end = mid - 1;
    }

    return -1;

}

int main()
{   
    vector <int> arr = {11, 12, 15, 18, 2,  5, 6, 8};
    int n = arr.size();
    cout<<rotIndex(arr, n);
    return 0;
}