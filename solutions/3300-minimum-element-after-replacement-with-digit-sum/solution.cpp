class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<string> str;

        for(int x: nums)
        {
            str.push_back(to_string(x));
        }

        vector<int> ans;

        for(string s: str)
        {
            int sum =0;
            for(char ch: s)
            {
                sum +=ch - '0';
            }
            ans.push_back(sum);
        }

        sort(ans.begin(), ans.end());

        return ans[0];
    }
};
