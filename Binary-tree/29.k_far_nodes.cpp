/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/
class Solution {
public:
    
    void printBelowAtK(TreeNode *root, TreeNode *block, int K, vector <int> &ans)
    {
        if(root == NULL || root == block || K < 0)
            return;
        
        if(K == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        printBelowAtK(root->left, block, K - 1, ans);
        printBelowAtK(root->right, block, K - 1, ans);
    }
    
    int helper(TreeNode *root, TreeNode *target, int K, vector <int> &ans)
    {
        if(root == NULL) return -1;
        
        if(root == target)
        {
            printBelowAtK(root, NULL, K, ans);
            return 1;
        }
        
        int leftResult = helper(root->left, target, K, ans);
        if(leftResult != -1)
        {
            printBelowAtK(root, root->left, K - leftResult, ans);
            return leftResult + 1;
        }
        
        int rightResult = helper(root->right, target, K, ans);
        if(rightResult != -1)
        {
            printBelowAtK(root, root->right, K - rightResult, ans);
            return rightResult + 1;
        }
        
        return -1;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        vector <int> ans;
        helper(root, target, K, ans);
        
        return ans;
    }
};