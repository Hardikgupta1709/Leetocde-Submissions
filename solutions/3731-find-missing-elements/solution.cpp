class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for(int i=1 ; i<nums.size(); i++)
            {
                int curr = nums[i-1]+1;
                while(curr < nums[i])
                {
                    ans.push_back(curr);
                    curr++ ;
                }
            }
        return ans;
    }
};
