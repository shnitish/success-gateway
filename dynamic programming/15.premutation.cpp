/*
https://www.geeksforgeeks.org/permutation-coefficient/
*/

#include <iostream>
#include <math.h>

typedef long long int ll;

using namespace std;

// O(n) time complexity
// O(n) sapce complexity
int permutationCoeff(ll n, ll r)
{   
    // to store factorial values upto n
    int fact[n + 1]; 
  
    // 0! = 1
    fact[0] = 1; 
    
    // calculate factorial and store in fact[]
    for(int i = 1; i <= n; i++) 
       fact[i] = i * fact[i - 1]; 
  

    // final nPr formula
    return fact[n] / fact[n - r]; 
}

// O(n) time complexity
// O(1) space complexity
int permut(ll n, ll r)
{
    int p = 1;

    for(int i = 0; i < r; i++)
        p = p * (n - i);
    
    return p;
}

int main()
{
    ll n = 5;
    ll r = 2;
    cout<<permutationCoeff(n, r);
}