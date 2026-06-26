class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int count  =0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int freqTarget =0;
            for(int j=i; j<nums.size(); j++)
            {
                int size =  j-i+1;
                if(nums[j] == target)
                {
                    freqTarget ++;
                }

                if(freqTarget > size/2)
                {
                    count ++;
                }
            }
        }
    return count;
    }
};
