/*
https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

No repition for ex (1 & 2) is exactly same as (2 & 1)

For n = 4

if 1 remains single then count ways for (n - 1) which is (2, 3 & 4) person to get paired 
if 1 pairs up with 2 then count ways for (n - 2) which is (3 & 4) person to get paired
if 1 pairs up with 3 then count ways for (n - 2) which is (2 & 4) person
if 1 pairs up wiht 4 then count ways for (n - 2) which is (2 & 3) person

so recurance is result[n] = result[n - 1] + result[n - 2](n - 1)

and keep storing these values into a array.
*/

#include <iostream>

using namespace std;

int friendsCount(int n)
{
    int result[n + 1];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;

    // calculate ways
    for(int i = 3; i <= n; i++)
    {
        result[i] = result[i - 1] + result[i - 2] * (i - 1);
    }

    // print array
    for(auto x: result)
        cout<<x<<" ";
    cout<<'\n';
    return result[n];
}

int main()
{
    int n = 4;
    cout<<friendsCount(n);
}