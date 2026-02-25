class Solution {
public:

    void solve(TreeNode* root, int targetSum, int currSum, int &found)
    {
        if(root == NULL)
        {
            return;
        }

        currSum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(currSum == targetSum)
            {
                found = 1;
            }
            return;
        }

        solve(root->left, targetSum, currSum, found);
        solve(root->right, targetSum, currSum, found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        int found = 0;
        solve(root, targetSum, 0, found);

        return found == 1;
    }
};
