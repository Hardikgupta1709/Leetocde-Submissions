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
    int countHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int heightLeft = countHeight(root-> left);
        int heightRight = countHeight(root-> right);
        
        return 1+ max(heightLeft,heightRight);
    }

    bool balanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        if(abs(countHeight(root->left) - countHeight(root->right)) >1)
        {
            return false;
        }
    return balanced(root->left) && balanced(root->right);
    }

    bool isBalanced(TreeNode* root) {

    bool isbalanced = balanced(root);

      if(isbalanced)
      {
        return true;
      }
      return false;
    }
};
