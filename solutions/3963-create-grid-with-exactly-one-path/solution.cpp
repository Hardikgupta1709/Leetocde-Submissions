class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n,'#'));

        if(m == 1 || n==1)
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    ans[i][j] = '.';
                }
            }
            return ans;
        }

        for(int i=0; i<n; i++)
        {
            ans[0][i] = '.';
        }

        for(int i=1; i<m; i++)
        {
            ans[i][n-1] = '.';
        }
    return ans;
    }
};
