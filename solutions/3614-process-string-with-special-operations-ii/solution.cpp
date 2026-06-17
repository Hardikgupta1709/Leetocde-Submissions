class Solution {
public:
    char processStr(string s, long long k) {
       vector<long long>len(s.size());

       long long currlen =0;

       for(int i=0; i<s.size(); i++)
       {
            if(s[i] >='a' && s[i] <= 'z')
            {
                currlen ++;
            }
            else if(s[i] == '#')
            {
                if(currlen > (long long)2e18)
                {
                    currlen  = (long long)4e18;
                }
                else
                {
                    currlen *= 2;
                }
            }
            else if(s[i] == '*')
            {
                if(currlen > 0)
                {
                    currlen --;
                }
            }
        len[i] = currlen;
       }

       if(currlen == 0 || k>= currlen)
       {
            return '.';
       }

       for(int i = s.size()-1; i>=0; i--)
       {
            long long beforelen = 0;

            if(i>0)
            {
                beforelen = len[i-1];
            }

            long long afterlen = len[i];

            if(s[i] >= 'a' && s[i] <= 'z')
            {
                if(k == afterlen -1)
                {
                    return s[i];
                }
            }

            else if(s[i] == '#' && beforelen >0) 
            {
                k %= beforelen;
            }

            else if(s[i] == '%')
            {
                k = afterlen-1-k;
            }
       }
    return '.';
    }
};
