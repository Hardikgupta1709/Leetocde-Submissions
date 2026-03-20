class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for(int i=0; i<=m-k; i++)
        {
            for(int j=0; j<=n-k; j++)
            {
                vector<int> flat;
                for(int x=i; x<i+k; x++)
                {
                    for(int y=j; y<j+k; y++)
                    {
                        flat.push_back(grid[x][y]);
                    }
                }
                sort(flat.begin(),flat.end());
                
                int min_diff = INT_MAX;
                for(int z=1; z<flat.size(); z++)
                {
                    if(flat[z] != flat[z-1])
                    {
                        min_diff = min(min_diff , flat[z]-flat[z-1]);
                    }
                }
                if(min_diff == INT_MAX)
                {
                    min_diff =0;
                }
            ans[i][j] = min_diff;
            }
        }
    return ans;
    }
};
