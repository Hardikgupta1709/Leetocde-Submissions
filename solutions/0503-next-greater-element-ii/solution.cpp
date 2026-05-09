class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int nextVal = -1;
            for(int j=1; j<n; j++)
            {
                int index = (i+j)%n;

                if(nums[i] < nums[index])
                {
                    nextVal = nums[index];
                    break;
                }
            }

            ans.push_back(nextVal);
        }
        
    return ans;
    }
};
