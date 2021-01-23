/*
Instead using a linked list in a bucket, we'll use a self balancing BST like set
which will bring down the complexities of add, remove and find from O(k) O(logk)
where
    k = items in bucket
    n = number of elements
    b = number of buckets
so there will be (n/b) elements per bucket which is k.

If b is larger than n, then the on the avg case the complexities will reduce to O(1).
*/
#include <bits/stdc++.h>

using namespace std;

// Every bucket has a collection of self balancing bst due to collisions in hash
struct bucket
{
    set<int> v;

    void add (int x)
    {
        v.insert (x);
    }

    void remove (int x)
    {
        v.erase (x);
    }

    bool find (int x)
    {
        return v.find (x) == v.end () ? 0 : 1;
    }
};

class hashSet
{
    int n; // no. of buckets
    bucket *container;

    // hash function
    int hash (int x)
    {
        return x % n;
    }

public:
    hashSet (int bucket_req)
    {
        n = bucket_req;
        container = new bucket[bucket_req];
    }

    // insert
    void insert (int item)
    {
        int b_no = hash(item);
        container[b_no].add(item);
    }

    // delete
    void remove (int item)
    {
        int b_no = hash(item);
        container[b_no].remove(item);
    }

    // search
    bool find (int item)
    {
        int b_no = hash(item);
        return (container[b_no].find(item));
    }
};

int main()
{
    int t = 1;
    while (t--)
    {
        hashSet hs(10);
        hs.insert(10);
        hs.insert(5);
        hs.insert(3);
    
        cout<<hs.find(3);
    }
    return 0;
}