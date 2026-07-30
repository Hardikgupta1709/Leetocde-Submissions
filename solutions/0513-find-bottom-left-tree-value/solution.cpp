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

        return max(left,right)+1;
    }

    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int ans =0;
        int length = height(root);
        int counter = 1;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(counter == length)
                {
                    ans = temp->val;
                    break;
                }

                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            counter ++;
        }
    return ans;
    }
};
