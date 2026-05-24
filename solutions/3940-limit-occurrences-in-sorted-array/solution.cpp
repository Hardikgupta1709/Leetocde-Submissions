class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> result;
        for(int i=0; i<nums.size(); )
            {
                int countEle = 0;
                int curr = nums[i];
                while(i<nums.size() && nums[i] == curr && countEle < k)
                    {
                        result.push_back(nums[i]);
                        countEle ++;
                        i++;
                    }
                while(i<nums.size() && nums[i] == curr)
                    {
                        i++;
                    }
            }
    return result;
    }
};
