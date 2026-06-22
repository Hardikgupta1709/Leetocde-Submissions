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
    void traverse(TreeNode* root, int targetSum,int currSum, vector<int>&path,vector<vector<int>>&ans)
    {
        if(root == NULL)
        {
            return ;
        }

        currSum += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            if(currSum == targetSum)
                ans.push_back(path);
        }


        traverse(root->left,targetSum,currSum,path,ans);
        traverse(root->right,targetSum,currSum,path,ans);

        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>path;
        int currSum=0;


        traverse(root,targetSum,currSum,path,ans);        

    return ans;
    }
};
