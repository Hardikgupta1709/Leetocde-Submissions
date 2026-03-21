class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

       int top= x; 
       int bottom= x+k-1;

       while(top < bottom)
       {
        int j=0;

        while(j< k)
        {
            swap(grid[top][y+j], grid[bottom][y+j]);
            j++;
        }
        top++;
        bottom--;
       } 
    return grid;
    }
};
