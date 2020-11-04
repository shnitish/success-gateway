/*
https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

(j - i + 1) -> size of the current window in the array
*/
#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector <int> arr, int k)
{
    int leftPtr, rightPtr = 0;
    int n = arr.size();
    int sum_ = 0;
    int max_ = INT8_MIN;

    while (rightPtr < n)
    {   
        // keep adding the sum
        sum_ += arr[rightPtr];

        if(rightPtr - leftPtr + 1 < k) 
            rightPtr++;
        
        // check if current window is equal to the given size k
        else if(rightPtr - leftPtr + 1 == k)
        {
            max_ = max(max_, sum_);
            sum_ -= arr[leftPtr]; //to shift window 1 step towards right
            leftPtr++;
            rightPtr++;
        }
    }

    return max_;
    
}

int main()
{   
    vector <int> arr = {2, 5, 1, 8, 2, 9 ,1};
    int k = 3;
    cout<<maxSum(arr, k);
    return 0;
}