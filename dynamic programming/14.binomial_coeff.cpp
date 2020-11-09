/*
https://practice.geeksforgeeks.org/problems/ncr1019/1#

if n == r then o/p = 1 for ex: 5c5 = 1
if r == 0 then o/p = 1 fro ex: 5c0 = 1
*/

#include <iostream>
#include <math.h>

typedef long long int ll;

using namespace std;

int binomialCoeff(ll n , ll r)
{   
    // to cover edge cases
    int mod = pow(10, 9) + 7;

    int result[n + 1][ r + 1];

    // edge case
    if(n < r)
        return 0;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= r; j++)
        {   
            if(j == 0 || j == i)
                result[i][j] = 1;

            else
                result[i][j] = (result[i - 1][j] + result[i - 1][j - 1]) % mod;
        }
    }

    return result[n][r];
}

int main()
{
    ll n = 5;
    ll r = 2;
    cout<<binomialCoeff(n, r);
}