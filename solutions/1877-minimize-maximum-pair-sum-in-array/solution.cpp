class Solution {
public:

    int solve(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int left =0;
        int right = nums.size() -1;

        int max_sum = INT_MIN;

        while(left<right)
        {
            int currSum = nums[left] + nums[right];
            max_sum = max(max_sum,currSum);
            left ++; 
            right --;
        }

    return max_sum;
    }

    int minPairSum(vector<int>& nums) {
        return solve(nums);
    }
};
