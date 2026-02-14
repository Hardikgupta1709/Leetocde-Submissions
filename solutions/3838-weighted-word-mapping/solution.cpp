class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        
        for(string s : words)
        {
            int total = 0;
            
            for(char i : s)
            {
                total += weights[i - 'a'];
            }
            
            int mod = total % 26;
            char mapped = 'z' - mod;
            
            ans += mapped;
        }
        
        return ans;   
    }
};

