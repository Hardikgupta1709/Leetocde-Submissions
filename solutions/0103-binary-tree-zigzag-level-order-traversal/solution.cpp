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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        int levelCnt =0;

        while(!q.empty())
        {
            vector<int> level ;
            int n = q.size();
            

            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left)
                    {
                        q.push(temp->left);
                    }
                if(temp->right)
                    {
                        q.push(temp->right);
                    }
            }
            if(levelCnt %2 != 0)
            {
                reverse(level.begin(),level.end());
            }
            levelCnt++;
            ans.push_back(level);
        }
    return ans;
    }
};
