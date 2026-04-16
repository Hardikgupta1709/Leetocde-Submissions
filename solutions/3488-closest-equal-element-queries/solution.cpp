class Solution {
public: 
    vector<int> solve(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> dp(n,n);

        for(int i=0; i< 2*n; i++)
        {
            int idx = i%n;
            int num = nums[idx];

            if(mp.count(num))
            {
                int prev = mp[num];
                int dist = i - prev;

                dp[idx] = min(dp[idx],dist);
                dp[prev % n] = min(dp[prev % n], dist);
            }
            mp[num] = i;
        }
    return dp;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> dp = solve(nums);
        vector<int>ans;
        int n = nums.size();

        for(int q: queries)
        {
            if(dp[q] == n)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(dp[q]);
            }
        }
    return ans;
    }    
};
