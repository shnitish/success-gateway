/*
https://www.geeksforgeeks.org/program-nth-catalan-number/

Logic 

C0 = 1
C1 = 1
C2 = C0.C1 + C1.C0
C3 = C0.C2 + C1.C1 + C2.C0
C4 = C0.C3 + C1.C2 + C2.C1 + C3.C0
.
.
.
*/

#include <iostream>

using namespace std;

int catalan(int n)
{   
    int result[n + 1];

    result[0] = 1;
    result[1] = 1;

    for(int i = 2; i <= n; ++i)
    {   result[i] = 0;
        for(int j = 0; j < i; j++)
            result[i] += result[j] * result[i - j - 1];
    }

    return result[n];
}

int main()
{   
    int n; cin>>n;
    cout<<catalan(n);
    return 0;
}