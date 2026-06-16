class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        string result;

        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]]++;
        }

        vector<pair<char,int>>v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b)
        {
            return a.second > b.second;
        });

        for(auto it: v)
        {
            result.append(it.second, it.first);
        }
    return result;
    }
};
