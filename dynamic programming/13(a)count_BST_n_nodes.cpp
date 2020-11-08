/*
Count Number of BST can be made with N number of nodes

The logic is same as catalan numbers.
With 0 nodes only 1 BST can be made
With 1 node onlye 1 BST can be made

2nodes = leftSubtree(0).rightSubTree(1) + leftSubTree(1).rightSubTree(0)
with 2 nodes either we can have 0 nodes in left and 1 node in right or 1 node in left subtree and 0 in right subtree
So the number of trees will be 

0*1 + 1*0 = 2

and same for n number of nodes.
*/

#include <bits/stdc++.h>

using namespace std;

int count(int n)
{
    int result[n + 1];
    result[0] = 1;
    result[1] = 1;

    for(int i = 2; i <= n; i++)
    {   result[i] = 0;

        int leftsubTree = 0;
        int rightsubTree = i - 1;

        while(leftsubTree <= i - 1)
        {   
            result[i] += result[leftsubTree] * result[rightsubTree];
            leftsubTree++;
            rightsubTree--;
        }
    }

    return result[n];
}

int main()
{   
    int n; cin>>n;
    cout<<count(n);
    return 0;
}