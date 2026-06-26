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
    void traversal(TreeNode* root, long long targetSum, vector<long long>& paths, long long& totalPaths)
    {
        if(root == NULL)
        {
            return ;
        }

        for(int i=0; i<paths.size(); i++)
        {
            paths[i] += root->val;

            if(paths[i] == targetSum)
            {
                totalPaths++;
            }
        }

        paths.push_back(root->val);

        if(root->val == targetSum)
        {
            totalPaths++;
        }

        traversal(root->left, targetSum, paths ,totalPaths);
        traversal(root->right, targetSum, paths ,totalPaths);

        paths.pop_back();
        for(int i=0; i<paths.size(); i++)
        {
            paths[i] -= root->val;
        }

    }

    int pathSum(TreeNode* root, int targetSum) {
        long long totalPaths = 0;

        vector<long long>paths;

        traversal(root,targetSum,paths,totalPaths);

    return totalPaths;
    }
};
