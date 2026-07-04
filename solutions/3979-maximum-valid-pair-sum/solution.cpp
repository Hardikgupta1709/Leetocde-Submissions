class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxi = INT_MIN;

        int n = nums.size();

        int bestFromLeft = nums[0];

        for(int i=k; i<n; i++)
            {
                bestFromLeft = max(bestFromLeft, nums[i-k]);
                maxi = max(maxi, bestFromLeft + nums[i]);
            }
        return maxi;
    }
};
