class Solution {
public:
    bool isPalindrome(string s) {
        
        string cleaned = "";
        for(char ch: s)
        {
            if(isalnum(ch))
            {
                cleaned += tolower(ch);
            }
        }
        
        s = cleaned;

        int i=0;
        int j=s.size()-1;


        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
                break;
            }
            i++;
            j--;
        }
    return true;
    }
};
