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
    void findDepth(TreeNode* root, int& maxi, int depth)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL)
        {
            maxi = max(maxi, depth);
        }

        findDepth(root->left, maxi,depth+1);
        findDepth(root->right, maxi, depth+1);
    }

    void traverse(TreeNode* root, int& sum, int depth, int maxi)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL && depth == maxi)
        {
            sum += root->val;
        }

        traverse(root->left,sum,depth+1,maxi);
        traverse(root->right,sum,depth+1,maxi);
    }

    int deepestLeavesSum(TreeNode* root) {
        int maxi =0;
        findDepth(root,maxi,0);
        int sum =0;
        
        traverse(root,sum,0,maxi);
    return sum;
    }
};
