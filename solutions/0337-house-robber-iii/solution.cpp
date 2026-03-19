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
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp)
    {
        if(root == NULL)
        {
            return 0;
        }

        if(dp.find(root) != dp.end())
        {
            return dp[root];
        }

        int inclu = root->val;
        if(root->left)
        {
            inclu += solve(root->left->left,dp);
            inclu += solve(root->left->right,dp);
        }
        if(root->right)
        {
            inclu +=solve(root->right->right,dp);
            inclu +=solve(root->right->left,dp);
        }
        int exclu = solve(root->left,dp) + solve(root->right,dp) ;

        dp[root] =  max(inclu,exclu);
        return dp[root];
    }

    int rob(TreeNode* root) {

        unordered_map<TreeNode*, int> dp;
        int ans = solve(root,dp);
    return ans;
    }
};
