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
    void subTree(TreeNode* root, int& maxi, int& count)
    {
        if(root == NULL)
        {
            maxi = INT_MIN;
            return ;
        }


        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        subTree(root->left,leftMax,count);
        subTree(root->right,rightMax,count);

        maxi = max(root->val,max(leftMax,rightMax));

        if(root->val == maxi)
        {
            count ++;
        }
    }
    
    int countDominantNodes(TreeNode* root) {
        int count =0;

        int maxi = INT_MIN;

        subTree(root,maxi,count);
    return count;
    }
};
