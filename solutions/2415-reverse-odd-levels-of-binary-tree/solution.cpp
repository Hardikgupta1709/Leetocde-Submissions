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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL)
        {
            return root;
        }

        int count =0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<TreeNode*> oddLevel;

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(count % 2 != 0)
                {
                    oddLevel.push_back(temp);
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
            int i=0; 
            int j=oddLevel.size()-1;

            while(i < j)
            {
                swap(oddLevel[i]->val,oddLevel[j]->val);
                i++;
                j--;
            } 
        count ++;
        }
    return root;
    }
};
