/*
Same as ceil for integer array

Given an array of letters sorted in ascending order, find the smallest letter in
the array which is greater than a given key letter.
*/

#include <bits/stdc++.h>

using namespace std;

void nextLetter(vector <char> arr, char letter)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    char result = '#';

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == letter)
            start = mid + 1;

        if(arr[mid] > letter)
        {
            result = arr[mid];
            end = mid - 1;
        }

        else if(arr[mid] < letter)
            start = mid + 1;
    }

    cout<<result;
}

int main()
{   
    vector <char> arr = {'a', 'c', 'f', 'h'};
    char letter = 'f';
    nextLetter(arr, letter);

    return 0;
}