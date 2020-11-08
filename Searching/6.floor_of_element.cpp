/*
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x.
*/

#include <iostream>
#include <vector>

using namespace std;

int floor(vector <int> arr, int key)
{
    int n = arr.size();
    int start = 0;
    int end =  n -1;
    int result = 0;
    
    while (start <= end)
    {
        int mid = start + (end - start)/2;

        // floor an element is the element iself 
        if(arr[mid] == key)
            return arr[mid];

        // means key is present in the right half
        if(arr[mid] < key)
         {   
             result = arr[mid];
             start = mid + 1;
         }
        
        // means key is present in the left half 
        else if(arr[mid] > key)
            end = mid - 1;

    }
    
    return result;

}

int main()
{   
    vector <int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int key = 5;
    cout<<floor(arr, key);
    return 0;
}