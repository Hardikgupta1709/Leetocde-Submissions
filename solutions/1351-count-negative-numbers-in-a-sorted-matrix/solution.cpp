class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (auto &row : grid) {
            for (int val : row) {
                if (val < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

