class Solution {
public:
    void convertToInt(vector<string>& nums, vector<int> &ans)
    {
        for(string s : nums)
        {    
            int num =0;

            for(char c : s)
            {
                num = num  *2 + (c- '0');
            }
        ans.push_back(num);
        }
    }

     string convertToBinary(int n, int len)
    {
        string res = "";

        if(n == 0)
            res = "0";

        while(n > 0)
        {
            res = char(n % 2 + '0') + res;
            n = n / 2;
        }

        while(res.size() < len)
            res = "0" + res;

        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> ans;
        convertToInt(nums,ans);
        sort(ans.begin(), ans.end());

        if(ans[0] != 0)
        {
            return convertToBinary(0, nums.size());
        }

        for(int i=1; i<ans.size(); i++)
        {
            if(ans[i] != ans[i-1] +1)
            {
                return convertToBinary(ans[i-1] +1, nums.size());
            }
        }
    return convertToBinary(ans.back()+1, nums.size());
    }
};
