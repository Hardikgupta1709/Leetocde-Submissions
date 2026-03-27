class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>final = mat;

        for(int i=0; i<m; i++)
        {
            if(i%2 == 0)
            {
                k = k % final[i].size();
                rotate(final[i].begin(),final[i].begin()+k,final[i].end());
            }
            else
            {
                k = k % final[i].size();
                rotate(final[i].begin(), final[i].end() - k, final[i].end());
            }
        }

        if(mat == final)
        {
            return true;
        }
    return false;
    }
};
