class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();

        long long int totalSum =0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                totalSum += grid[i][j];
            }
        }

        long long int sumTemp1 =0;
        for(int i=0; i<m-1; i++)
        {
            for(int j=0; j<n; j++)
            {
                sumTemp1 += grid[i][j];
            }

            if(sumTemp1 == totalSum - sumTemp1)
            {
                return true;
            }
        }

        long long sumTemp2 =0;
        for(int j=0; j<n-1; j++)
        {
            for(int i=0; i<m; i++)
            {
                sumTemp2 += grid[i][j];
            }

            if(sumTemp2 == totalSum - sumTemp2)
            {
                return true;
            }
        }
    return false;
    }
};
