#include <iostream>
#include <vector>

using namespace std;

int reverseSearch(vector <int> arr, int key)
{   
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {   
        int mid = start + (end - start)/2;

        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] > key)
            start = mid + 1;
        
        else 
            end = mid - 1;
    }
    
    return -1;
    
}

int main()
{   
    vector <int> arr = {40, 10, 4, 3, 2};
    int n = arr.size();
    cout<<reverseSearch(arr, 10);
    return 0;
}