#include <iostream>

using namespace std;

// partition the array in a way
// such that the elements less than pivot are on its left
// and greater than pivot are on right
// and pivot sits at it's correct index
int partition(int arr[],int pivot, int lo, int hi)
{
    int i = lo;
    int j = lo;

    while (i <= hi)
    {
        if(arr[i] > pivot)
            i++;
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    // return pivot's index
    return j - 1;   
}

void quickSort(int arr[], int lo, int hi)
{   
    if( lo >= hi) // if both points to the same index or low pasts high then return.
        return;

    int pivot = arr[hi];
    int pi = partition(arr,pivot, lo, hi); // pi holds the pivot's index after partition is performed
    quickSort(arr, lo, pi - 1);         
    quickSort(arr, pi + 1, hi);
    
}

int main()
{   
    int arr[] = {8, 5, 1, 3 , 7, 2, 9, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(auto x: arr)
        cout<<x<<" ";
    return 0;
}