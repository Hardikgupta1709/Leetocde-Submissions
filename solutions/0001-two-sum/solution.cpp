class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indiceStore;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int sum = nums[i]+nums[j];
                if(sum == target)
                {
                    indiceStore.push_back(i);
                    indiceStore.push_back(j);
                }
            }
        }
        return indiceStore;
    }
};
