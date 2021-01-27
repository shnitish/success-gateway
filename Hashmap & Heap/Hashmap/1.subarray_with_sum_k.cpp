/*
https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map <int, int> umap;
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum == k)
                count++;
            
            int temp = sum - k;
            
            if(umap.find(temp) != umap.end())
                count += umap[temp];
            
            umap[sum] += 1;
        }
        
        return count;
        
    }
};