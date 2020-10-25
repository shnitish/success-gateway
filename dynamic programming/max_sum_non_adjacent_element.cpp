/*
https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

inclusive keeps track of the maximum sum including the previous element ( means excluding the current element in the array)
exclusive keeps the track of the maximum sum excluding the previous element (means including the current element in the array)

if arr[i] is included then arr[i - 1] is excluded so add the exlcusive value with the element and 
find max(if exlcuding current element, if including current element + max value excluding previous element)
   ->max(inclsive, arr[i] + exclusive);
then update the exclusive with the previous inclusive

return inclusive

TC = O(n)
*/
#include <iostream>

using namespace std;

int maxSum(int arr[], int n)
{
    int inclusive = arr[0];
    int exclusive = 0;

    for(int i = 1; i < n; i++)
    {
        int temp = inclusive; //store current inclusive
        
        inclusive = max(inclusive, arr[i] + exclusive);
        exclusive = temp;
    }

    return inclusive;
}

int main()
{   
    int arr[] = {5, 2, 2, 5 ,3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr, n);
    return 0;
}