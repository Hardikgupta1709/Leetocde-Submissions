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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }

        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        int index = 0;
        while(inorder[index] != rootValue)
        {
            index ++;
        }
        
        vector<int> left(inorder.begin(),inorder.begin() + index);
        vector<int> right(inorder.begin() +1 + index, inorder.end());

        vector<int> leftPre(preorder.begin()+1,preorder.begin() +1 + left.size());
        vector<int> rightPre(preorder.begin() +1 + left.size(), preorder.end());


        root->left = buildTree(leftPre, left);
        root->right = buildTree(rightPre, right);

    return root;
    }
};
