/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Search in the rotated sorted array
*/

#include <iostream>
#include <vector>

using namespace std;

// ordinary binary search
int binarySearch(vector <int> arr, int key, int low, int high)
{
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] >= key)
            high = mid - 1;
        
        else 
            low = mid + 1;
    }

    return -1;
}

// find out the index of the min element
int minElementIndex(vector <int> arr, int n)
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
    int key = 15;
    int minidx = minElementIndex(arr, n);
    
    //binary search on the left and right side of the minimum element
    //either of the sides contain the key element which has to be found.
    int leftSearch = binarySearch(arr, key, 0, minidx - 1);
    int rightSearch = binarySearch(arr, key, minidx + 1, n - 1);

    if(leftSearch == -1)
        cout<<rightSearch;
    else
        cout<<leftSearch;

    return 0;
}