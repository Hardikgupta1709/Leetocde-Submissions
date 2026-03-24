class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int MOD = 12345;
        vector<vector<int>> p(n, vector<int>(m));
        
        vector<int> arr;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        
        int size = m*n;
        vector<int> prefix(size,1), suffix(size,1);

        for(int i=1; i<size; i++)
        {
            prefix[i] = ((long long)prefix[i-1]* arr[i-1])%MOD;
        }

        for(int i= size-2; i>=0; i--)
        {
            suffix[i] = ((long long)suffix[i+1]* arr[i+1])% MOD;
        }

        for(int i=0; i< size; i++)
        {
            p[i/m][i%m] = ((long long)prefix[i]* suffix[i])% MOD;
        }
    return p;
    }
};
