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

    void solve(TreeNode* root, int path, vector<int>& result)
    {
        if(root == NULL)
        {
            return ;
        }

        path = path * 10 + root->val;

        if(! root->left && !root->right)
        {
            result.push_back(path);
            return ;
        }

         solve(root->left, path, result);
         solve(root->right,  path, result);

    }

    int sumNumbers(TreeNode* root) {
        vector<int>result;
        int ans =0;

        solve(root,0, result);

        for(auto i: result)
        {
            ans += i;
        }

    return ans;
    }
};
