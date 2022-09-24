/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void solve(TreeNode *root,int targetSum,vector<int> ds,vector<vector<int>> &ans)
    {
        if(root==NULL) return;
        ds.push_back(root->val);
        targetSum=targetSum-root->val;
        if(targetSum==0 && root->left==NULL && root->right==NULL)
        {
            ans.push_back(ds);
            return;
        }
        solve(root->left,targetSum,ds,ans);
        solve(root->right,targetSum,ds,ans);
    }
   
       
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root,targetSum,ds,ans);
        return ans;
    }
    
};