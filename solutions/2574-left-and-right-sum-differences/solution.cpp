class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());

        vector<int> prefix(nums.size());

        prefix[0] = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                prefix[i] = prefix[i-1] + nums[i];
            }
        }

        vector<int> suffix(nums.size());

        suffix[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] != 0)
            {
                suffix[i] = suffix[i+1] + nums[i];
            }
        }

        for(int i=0; i<nums.size(); i++)
        {
            int leftsum = 0;
            int rightsum = 0;

            if(i > 0)
            {
                leftsum = prefix[i-1];
            }

            if(i < nums.size()-1)
            {
                rightsum = suffix[i+1];
            }
            ans[i] = abs(leftsum - rightsum);
        }
    return ans;
    }
};
