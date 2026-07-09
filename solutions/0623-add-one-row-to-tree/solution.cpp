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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int counter =1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();

            if(counter == depth-1)
            {
                for(int i=0; i<n; i++)
                {
                    TreeNode* temp = q.front();
                    q.pop();

                    TreeNode* Newleft = new TreeNode(val);
                    TreeNode* Newright = new TreeNode(val);

                    TreeNode* forwardRight = temp->right;
                    TreeNode* forwardLeft = temp->left;

                    temp->left = Newleft;
                    temp->right = Newright;

                    Newleft->left = forwardLeft;
                    Newright->right = forwardRight;
                }
            return root;
            }

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

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
    return root;
    }
};
