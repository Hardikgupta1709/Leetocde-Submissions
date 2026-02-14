class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<int> torunelixa = nums;  
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<long long> dp(n);
        
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            long long take = 0;
            
            if(colors[i] == colors[i-1])
            {
                take = nums[i];
                if(i > 1)
                    take += dp[i-2];
            }
            else
            {
                take = nums[i] + dp[i-1];
            }
            
            dp[i] = max(dp[i-1], take);
        }
        
        return dp[n-1];
    }
};


