class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        if(k<=1)
        {
            return 0;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        int mini = INT_MAX;
        
        for(int i=0; i+k-1<nums.size(); i++)
        {
            int s = nums[i] - nums[i+k-1];

            mini = min(mini,s);
        }
        return mini;
    }
};
