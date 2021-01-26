/*
https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

Using min heap
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size() == 0)
            return -1;
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int i = 0; i < nums.size(); i++)
        {
            min_heap.push(nums[i]);
            
            if(min_heap.size() > k)
                min_heap.pop();            
        }
        
        return min_heap.top();
    }
};