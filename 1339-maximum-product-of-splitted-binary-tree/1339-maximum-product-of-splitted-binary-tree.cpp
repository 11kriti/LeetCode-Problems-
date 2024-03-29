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

    long long totalSum = 0;
    long long mod = 1e9+7;

    // total sum of tree
    void TotalSum(TreeNode* root)
    {
        if(root==NULL) return;

        TotalSum(root->left);
        TotalSum(root->right);

        totalSum += root->val;
    }

    long SubtreeSum(TreeNode* root,long long &maxPro)
    {
        if(root==NULL) return 0;

        long l = SubtreeSum(root->left,maxPro);
        long r = SubtreeSum(root->right,maxPro);

        long curr_sum = l + r + root->val;                                  // curr subtree sum
        long curr_Pro = (curr_sum * (totalSum - curr_sum));                 // curr product

        if(maxPro < curr_Pro)
        {
            maxPro = curr_Pro;
        }

        return curr_sum;                  // for each node return their subtree sum for upcoming nodes pro calculations
    }

    int maxProduct(TreeNode* root) 
    {
        // First we will calculate the sum of whole tree
        // then we will calculate the sum of subtree for each node Individually
        // now we will calculate the product -> ( subtree sum for node * (total sum - subtree sum for node) )

        TotalSum(root);

        long long maxPro = 1;
        SubtreeSum(root,maxPro);

        return (maxPro % mod);
    }
};