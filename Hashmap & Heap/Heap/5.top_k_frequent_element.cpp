/*
Top k frequent elements using min heap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> v;
        unordered_map <int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for(int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        
        for(auto val: map)
        {
            // second is the frequency in map and first is the number itself
            heap.push(make_pair(val.second, val.first));

            if(heap.size() > k)
                heap.pop();
        }

        while(!heap.empty())
        {
            v.push_back(heap.top().second);
            heap.pop();
        }
    return v;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector <int> v= s.topKFrequent(nums, k);
    for(auto x: v)
        cout<<x<<" ";
    
    return 0;
}