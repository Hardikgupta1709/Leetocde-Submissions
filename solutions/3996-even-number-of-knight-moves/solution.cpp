class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int starts = (start[0] + start[1])%2;
        int ends = (target[0] + target[1])%2;

        if(starts == ends)
        {
            return true;
        }
    return false;
    }
};
