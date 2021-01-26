/*
Using max heap
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int k)
{
    priority_queue<int> heap;

    for (int i = 0; i < n; i++)
    {
        heap.push(arr[i]);

        if (heap.size() > k)
            heap.pop();
    }

    return heap.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    cout << solve(arr, n, k);
    return 0;
}