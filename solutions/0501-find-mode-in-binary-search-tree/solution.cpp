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
    void solve(TreeNode* root,  unordered_map<int,int>& mp)
    {
        if(root == NULL)
        {
            return ;
        }

        solve(root->left,mp);
        mp[root->val] ++;
        solve(root->right,mp);
    }

    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        solve(root,mp);

        int maxFreq =0;
        for(auto it: mp)
        {
            maxFreq = max(it.second,maxFreq);
        }

        for(auto it: mp)
        {
            if(it.second == maxFreq)
            {
                ans.push_back(it.first);
            }
        }

    return ans;
    }
};
