class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> maxiA(n);
        vector<int> miniA(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;


        for(int i=0; i<n; i++)
        {
            maxi = max(maxi,nums[i]);
            maxiA[i] = maxi;
        }

        for(int i = n-1; i>=0; i--)
        {
            mini = min(mini,nums[i]);
            miniA[i] = mini;
        }

        int score =0;

        for(int i=0; i<n; i++)
        {
            int score = maxiA[i] - miniA[i];
            if(score <= k)
            {
                return i;
            }
        }
    return -1;
    }
};
