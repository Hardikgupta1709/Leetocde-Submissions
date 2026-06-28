class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        long long sum =0;

        for(int i=0; i<k; i++)
            {
                long long normal = nums[i];
                long long multiply = (long long) nums[i]* mul;

                sum += max(normal,multiply);
                mul--;
            }
        return sum;
    }
};
