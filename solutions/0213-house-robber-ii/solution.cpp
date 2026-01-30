class Solution {
public:
    int solve(vector<int>&nums, vector<int>& dp, int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return nums[0];
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        int exclu = solve(nums, dp, n-2) + nums[n];
        int inclu = solve(nums, dp, n-1) ;

        dp[n] = max(inclu,exclu);

        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first,second;

        if(n==1)
        {
            return nums[0];
        }

        for(int i=0; i<n; i++)
        {
            if(i != n-1)
            {
                first.push_back(nums[i]);
            }

            if(i != 0 )
            {
                second.push_back(nums[i]);
            }
        }

        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);
        return max(
            solve(first, dp1, first.size() - 1),
            solve(second, dp2, second.size() - 1)
        );

    }
};
