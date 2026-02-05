class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        vector<int> result;
        int n = nums.size();

        int i=0;
        while(i< n)
        {
            if(nums[i] == 0)
            {
                result.push_back(0);
            }
            else 
            {
                int index = (i + nums[i])% n;
                if(index < 0)
                {
                    index +=n;
                }

                result.push_back(nums[index]);
            }
            i++;
        }
    return result;
    }
};
