#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {   
        int mid = start + (end - start)/2;

        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            end = mid - 1;
        
        else
            start = mid + 1;
    }
    return -1;    
}   

int main()
{
    int arr[] = { 2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr, n, 10);

    return 0;
}