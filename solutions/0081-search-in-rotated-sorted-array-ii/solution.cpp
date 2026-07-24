class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        int mid = (start+end)/2;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                return true;
            }

            if(nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                start++;
                end--;

                if(start > end)
                {
                    break;
                }

                mid = (start+end)/2;
                continue;
            }

            if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && target < nums[mid])
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }

            mid = (start+end)/2;
        }

        return false;
    }
};
