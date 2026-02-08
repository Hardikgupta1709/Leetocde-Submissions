class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        vector<long long> result;

        for (int i = 0; i < nums.size(); i++)
        {
            long long curr = nums[i];

            while (!result.empty() && result.back() == curr)
            {
                curr += result.back();
                result.pop_back();
            }

            result.push_back(curr);
        }

        return result;
    }
};

