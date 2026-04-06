class Solution {
public:
    bool judgeCircle(string moves) {

        unordered_map<int,int> freq;
        for(char ch: moves)
        {
            freq[ch]++;
        }

        if(freq['U'] == freq['D'] && freq['L'] == freq['R'])
        {
            return true;
        }
    return false;
    }
};
