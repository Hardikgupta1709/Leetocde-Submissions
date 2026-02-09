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
    int height (TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

    return 1+ max(leftHeight,rightHeight);
    }

    bool isbalanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        if(abs(height(root->left)- height(root->right))>1)
        {
            return false;
        }
    return isbalanced(root->left) && isbalanced(root->right);
    }

    void inorder(TreeNode* root, vector<int> & res)
    {
        if(root == NULL)
        {
            return ;
        }

        inorder(root->left,res);
        res.push_back(root->val);
         inorder(root->right,res);
    }

     TreeNode* buildTree(TreeNode* root) {

        vector<int> res;
        inorder(root, res);
        return buildFromSorted(res, 0, res.size() - 1);

    }

      TreeNode* buildFromSorted(vector<int>& res, int left, int right) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(res[mid]);

        root->left = buildFromSorted(res, left, mid - 1);
        root->right = buildFromSorted(res, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        if(isbalanced(root))
        {
            return root;
        }

        TreeNode * build = buildTree(root);

        return build;
    }
};
