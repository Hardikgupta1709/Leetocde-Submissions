class Solution {
public:
    int solve(vector<int>& nums, int start, int end, int target)
    {
        if(start > end)
        {
            return -1;
        }
        int mid = start + (end - start) / 2;

        if(nums[mid] == target)
        {
            return mid;
        }
        else if (target < nums[mid] )
        {
            return solve(nums,start,mid-1,target);
        }
        else
        {
            return solve(nums,mid+1,end,target);
        }
    return 0;
    }
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        int ans = solve(nums,start,end,target);

    return ans;
    }
};
