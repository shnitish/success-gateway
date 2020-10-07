/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector < vector<int> > result;
        
        if(!root)
            return result;
        
        queue <TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector <int> cur_level;
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                cur_level.push_back(temp->val);
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            result.push_back(cur_level);
            
        }
        return result;
    }
};