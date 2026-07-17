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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }

        int counter =0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();

            vector<int> oddLevel;
            vector<int> evenLevel;

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(counter %2 ==0)
                {
                    oddLevel.push_back(temp->val);
                }
                else
                {
                    evenLevel.push_back(temp->val);
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

            if(counter % 2 ==0)
            {
                for(int i=0; i<oddLevel.size(); i++)
                {
                    if(oddLevel[i] % 2 == 0) 
                    {
                        return false;
                    }
                    if(i>0 && oddLevel[i]<=oddLevel[i-1])
                    {
                        return false;
                    }
                }
            }
            else
            {
                for(int i=0; i<evenLevel.size(); i++)
                {
                    if(evenLevel[i] % 2 != 0) 
                    {
                        return false;
                    }
                    if(i>0 && evenLevel[i]>=evenLevel[i-1])
                    {
                        return false;
                    }
                }
            }
            counter ++;
        }
    return true;
    }
};
