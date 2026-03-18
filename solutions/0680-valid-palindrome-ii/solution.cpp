class Solution {
public:
    bool ispallindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
    return true;
    }

    bool validPalindrome(string s) {
        int i =0, j= s.size()-1;

        while(i<j)
        {
            if(s[i] != s[j])
            {
               string s1 =s;
               string s2 =s;

               s1.erase(i,1);

               cout << s1;

               s2.erase(j,1);
               cout << s2;

               return ispallindrome(s1) || ispallindrome(s2);
            }
            i++;
            j--;
        }
    return true;
    }
};
