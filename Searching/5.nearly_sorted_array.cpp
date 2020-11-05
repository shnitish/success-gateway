/*
https://www.geeksforgeeks.org/search-almost-sorted-array/

Search an element in a nearly sorted array.

Nearly sorted array is such that after modification
the ith element must moved to (i-1) or ith or (i+1) index 

*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector <int> arr, int key)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        // to keep check we don't go 'array out of bound'
        if(mid - 1 >= start && arr[mid - 1] == key)
            return mid - 1;

        // to keep check we don't go beyond array
        if(mid + 1 <= end && arr[mid + 1] == key)
            return mid + 1;
        
        // keep searching in the right half
        if(mid <= key)
            start = mid + 2;
        
        // keep searching in the left half
        else if(mid >= key)
            end = mid - 2;
        
    }

    return -1;
}

int main()
{
    vector <int> arr = {10, 3, 40, 20, 50, 80, 70};
    int key = 40;
    cout<<search(arr, key);
    return 0;

}