/*
https://leetcode.com/problems/maximum-binary-tree/
*/

// Method 1 O(n^2) TC

class Solution {
public:
    
    TreeNode *buildTree(int l, int r, vector <int> nums)
    {
        if(l > r)
            return NULL;
        
        // find max
        int x = nums[l];
        int index = l;
        for(int i = l; i <= r; i++)
        {
            if(nums[i] > x)
            {
                x = nums[i];
                index = i;
            }    
        }
    
        TreeNode *root = new TreeNode(nums[index]);
        
        // assign left and right child to the root
        root->left = buildTree(l, index - 1, nums);
        root->right = buildTree(index + 1, r, nums);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(0, nums.size() - 1, nums);
        
    }
};


// Method 2 ~O(n) TC
// https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C++-O(N)-solution
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};