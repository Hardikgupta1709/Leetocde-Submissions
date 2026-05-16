class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Row = matrix.size();
        int Col = matrix[0].size();
        int start = 0;
        int end = Row*Col -1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            int val = matrix[mid/Col][mid % Col];

            if(val == target)
            {
                return true;
            }
            else if(val < target)
            {
                start = mid +1;
            }
            else
            {
                end = mid-1;
            }
        }
    return false;
    }
};
