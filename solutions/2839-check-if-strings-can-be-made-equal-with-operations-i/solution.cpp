class Solution {
public:
    bool solve(string &s1, string &s2, int idx)
    {
        if(s1 == s2)
        {
            return true;
        }
        for(int i=idx; i<s1.size(); i++)
        {
            for(int j=i+2; j<s1.size();j+=2)
            {
                swap(s1[i],s1[j]);
                if (solve(s1, s2, i + 1)) 
                {
                    return true;
                }
                swap(s1[i],s1[j]);
            }
        }
    return false;
    }

    bool canBeEqual(string s1, string s2) {
        return solve(s1,s2,0);
    }
};
