class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int idx = -1;

        vector<int>leftSum(nums.size(),0);
        for(int i=1; i<nums.size(); i++)
        {
            leftSum[i] = nums[i-1] + leftSum[i-1];
        }

        vector<int>rightSum(nums.size(),0);
        for(int i=nums.size()-2; i>=0; i--)
        {
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(leftSum[i] == rightSum[i])
            {
                idx =i;
                break;
            }
        }
    return idx;
    }
};
