/*
https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

Find the first and last position of a repeating element in a sorted array.
*/

#include <iostream>
#include <vector>


using namespace std;

pair <int, int> search(vector <int> arr, int key)
{   
    int start = 0;
    int end = arr.size() - 1;
    int firstOccur, lastOccur;

    pair <int, int> result;

    // first occurance
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == key)
        {
            firstOccur = mid;
            end = mid - 1;
        }

        else if (arr[mid] > key)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }   

    start = 0;
    end = arr.size() - 1;

    // Last occurance
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == key)
        {
            lastOccur = mid;
            start = mid + 1;
        }

        else if(arr[mid] > key)
        {
            end = mid - 1;
        }
        
        else
        {
            start = mid + 1;
        }
        
    }

       result.first = firstOccur;
       result.second = lastOccur;

       return result;


}

int main()
{   
    vector <int> arr = {2, 4, 10, 10, 10, 18, 20};
    int key = 10;
    pair <int, int> result = search(arr, key);
    cout<<"First occurance of "<<key<<" at :"<<result.first<<endl;
    cout<<"Last occurance "<<key<<" at :"<<result.second;

    return 0;
}