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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int ans = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            int n = q.size();

            unsigned long long mini = q.front().second;
            unsigned long long first = 0;
            unsigned long long last = 0;

            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front().first;
                unsigned long long index = q.front().second - mini;
                q.pop();

                if(i == 0)
                {
                    first = index;
                }

                if(i == n - 1)
                {
                    last = index;
                }

                if(temp->left)
                {
                    q.push({temp->left, 2 * index + 1});
                }

                if(temp->right)
                {
                    q.push({temp->right, 2 * index + 2});
                }
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};
