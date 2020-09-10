#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> arr;


int solve(int l, int r)
 {
	ll total = 0;
	ll left_sum = 0;

    if (r-l <= 1)
        return 0;

    // sum of array
    for (int i = l; i < r; ++i)
    {
    	total += arr[i];
    }

    for (int i = l; i < r; i++)
    {
        left_sum += arr[i];
        
        if (left_sum * 2 == total) 
        {
            return 1 + max(solve(l, i+1), solve(i+1, r));
        }
    }

    return 0;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(0, n) << endl;
    }
}
