class Solution {
public:
    bool is_sorted(vector<int>&nums)
    {
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                return false;
                break;
            }
        }
    return true;
    }

    bool check(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++)
        {
            int start = nums[0];
            nums.erase(nums.begin());
            nums.push_back(start);

            if(is_sorted(nums))
            {
                return true;
            }
        }
    return false;
    }
};
