class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> all;
        int maxi = INT_MIN;
        int ans =0;

        for(int i=0; i<nums.size(); i++)
            {
                string digit = to_string(nums[i]);

                int largest = INT_MIN;
                int smallest = INT_MAX;

                for(char c : digit)
                    {
                        int d = c - '0';
                        largest = max(largest, d);
                        smallest = min(smallest, d);
                    }

                int range = largest - smallest;
                all.push_back(range);
            }

        for(int i=0; i<all.size(); i++)
            {
                maxi = max(maxi, all[i]);
            }

        for(int i=0; i<all.size(); i++)
            {
                if(maxi == all[i])
                {
                    ans += nums[i];
                }
            }
        return ans;
    }
};
