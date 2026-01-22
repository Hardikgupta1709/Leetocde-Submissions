class Solution {
public:
    bool sorted(vector<int>& nums)
    {
        int n = nums.size();

        for(int i =0; i+1<n; i++)
        {
            if(nums[i]>nums[i+1])
                return false;
        }
    return true;
    }

    int solve (vector<int>& nums,map<vector<int>,int>& dp)
    {
        int n = nums.size();
        if(sorted(nums))
            {
                return 0;
            }

        if(dp.count(nums))
            {
                return dp[nums];
            } 

        int min_sum = nums[0] + nums[1];
        int index = 0;    
        for(int i=1; i+1<n; i++)
        {
            int s = nums[i] + nums[i+1];

            if( s< min_sum)
            {
                min_sum = s;
                index =i;
            }
        }

        vector<int> next;
        for(int i=0; i<index; i++)
        {
            next.push_back(nums[i]);
        }

        next.push_back(nums[index] + nums[index+1]);

        for(int i=index +2; i<nums.size(); i++)
        {
            next.push_back(nums[i]);
        }

        return dp[nums] = 1+ solve(next,dp);


    }

    int minimumPairRemoval(vector<int>& nums) {

       map<vector<int>,int> dp;
       return solve(nums,dp);
    }
};
