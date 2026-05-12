class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxiV(n);
        vector<int> miniV(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
            maxiV[i] = maxi;
        }

        for(int i= n-1; i>=0; i--)
        {
            mini = min(mini, nums[i]);
            miniV[i] = mini;
        }

        int score =0;

        for(int i=0; i<n; i++)
        {
            score = maxiV[i] - miniV[i];
            if(score <=k)
            {
                return i;
            }
        }
    return -1;
    }
};
