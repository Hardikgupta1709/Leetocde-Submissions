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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

    return max(left,right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int o1 = diameterOfBinaryTree(root->left);
        int o2 = diameterOfBinaryTree(root->right);
        int o3 = height(root->left) + height(root->right);

        int ans =  max(o1,max(o2,o3));
    return ans;
    }
};
