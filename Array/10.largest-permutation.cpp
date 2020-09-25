/*

For example, if arr = [1,2,3,4]  and the maximum swaps k = 1 , the following arrays can be formed by swapping the 1
with the other elements:

[2,1,3,4]
[3,2,1,4]
[4,2,3,1]

The highest value of the four (including the original) is [4,2,3,1] k>=2
, we can swap to the highest possible value: [4,2,3,1]

Sample Input 0

5 1
4 2 3 5 1
Sample Output 0

5 2 3 4 1

*/


#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

void permutations(vector <ll> v, ll n, ll k)
{
	unordered_map <ll, ll> umap;
	priority_queue <ll> q;

	for (ll i = 0; i < n; ++i)
	 {
	 	umap[v[i]] = i;
	 	q.push(v[i]);
	 } 

	 for (ll i = 0; i < n; ++i)
	 {
	 	if (q.top() != v[i])
	 	{
	 		k--;

	 		ll index = umap[q.top()];
	 		swap(v[i], v[index]);	 	
	 		umap[v[index]] = index;
	 	}

	 	q.pop();

	 	if(k == 0)
	 		break;
	 }

	 for(ll x: v)
	 	cout<<x<<" ";
}

int main()
{	
	ll n, k;
	cin>>n;
	cin>>k;
	vector <ll> v(n);
	for(ll i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	permutations(v, n, k);
	return 0;
}