class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hm;
        unordered_map<char,bool> visited;

        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(hm.find(s[i]) != hm.end())
            {
                if(hm[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                if(visited[t[i]])
                {
                    return false;
                }
                hm.insert({s[i],t[i]});
                visited[t[i]] = true;
            }
        }
    return true;
    }
};
