class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;
        
        for(int i: nums)
        {
            string convert = "";
            convert = to_string(i);
            for(char ch : convert)
            {
                ans.push_back(ch - '0');
            }
        }

    return ans;
    }
};
