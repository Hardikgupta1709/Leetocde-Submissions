class Solution {
public:
    char makeMirror(char ch)
    {
        if(ch >= 'a' && ch <= 'z')
        {
            return 'a' + 'z' -ch;
        }
        else
        {
            return '0' +'9' -ch;
        }
    }
    
    int mirrorFrequency(string s) {
        int ans =0;

        unordered_map<char,int> cmFreq;
        
        for(char ch: s)
            {
                cmFreq[ch]++;
            }

         unordered_set<char> visited;

        for(auto it: cmFreq)
        {
            char ch = it.first;
            char mirror = makeMirror(ch);

            if(visited.count(ch)) continue;

            int f1 = cmFreq[ch];
            int f2 = cmFreq.count(mirror) ? cmFreq[mirror] : 0;

            ans += abs(f1 - f2);

            visited.insert(ch);
            visited.insert(mirror);
        }

    return ans;
    }
};
