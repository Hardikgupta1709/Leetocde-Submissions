class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappear;

        int n = nums.size();

        unordered_set<int> seen;

        for(int x : nums)
        {
            seen.insert(x);
        }

        for(int i=1; i<=n; i++)
        {
            if(seen.find(i) == seen.end())
            {
                disappear.push_back(i);
            }
        }
    return disappear;
    }
};
