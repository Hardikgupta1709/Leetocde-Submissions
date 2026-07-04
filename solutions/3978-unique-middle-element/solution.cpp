class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i=0; i<nums.size(); i++)
            {
                freq[nums[i]] ++;
            }

        int middleidx = nums.size()/2;

        int middleelement = nums[middleidx];

        if(freq[middleelement] ==1)
        {
            return true;
        }
    return false;
    }
};
