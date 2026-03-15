class Solution {
public:
    
    int solve( int i,vector<int>& dp)
    {
        if(i==1 || i== 0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        dp[i] =  (solve(i-1,dp)+solve(i-2,dp));
        return dp[i];

    }

    int climbStairs(int n) {

        vector<int> dp(n+1,-1);
        int ans = solve(n,dp);
    return ans;
    }
};
