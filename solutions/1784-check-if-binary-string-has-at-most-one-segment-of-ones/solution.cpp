class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroFound = false;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '0')
            {
                zeroFound = true;
            }
            else if(s[i] == '1' && zeroFound)
            {
                return false;
            }
        }
    return true;
    }
};
