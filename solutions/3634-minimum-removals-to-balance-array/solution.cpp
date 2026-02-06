class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count =0;
        int n = nums.size();
        
        for(int j=0; j<n; j++)
        {
            if(count<= j && (long long)nums[j] > (long long)nums[count] * k)
            {
                count ++;
            }
        }
        
    return count;
    }
};
