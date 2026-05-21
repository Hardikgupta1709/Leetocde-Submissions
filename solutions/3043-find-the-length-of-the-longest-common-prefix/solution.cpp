class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans =0; 

        unordered_set<string> prefixes;

        for(int x: arr1)
        {
            string s= to_string(x);
            string temp = "";

            for(char ch : s)
            {
                temp += ch;
                prefixes.insert(temp);
            }
        }

        for(int x: arr2)
        {
            string s= to_string(x);
            string temp ="";

            for(char ch : s)
            {
                temp += ch;

                if(prefixes.count(temp))
                {
                    ans = max(ans,(int)temp.size());
                }
            }
        }
    return ans;
    }
};
