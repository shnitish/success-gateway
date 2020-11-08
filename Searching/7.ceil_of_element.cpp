/*
Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x,
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

        // if element present then ceil of the element is the element itself
        if(arr[mid] == key)
            return arr[mid];
        
        // means key present on the right half of the array
        if(arr[mid] < key)   
             start = mid + 1;

        // means key is present in the left half
        else if(arr[mid] > key)
        {   
            result = arr[mid];
            end = mid - 1;
        }
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