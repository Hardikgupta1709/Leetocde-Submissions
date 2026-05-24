class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;

        unordered_map<int,int> freq;

        for(char ch : password)
            {
                freq[ch] ++;
            }

        string noDup = "";

        for(char ch : password)
            {
                if(freq[ch] > 0)
                {
                    noDup += ch;
                    freq[ch] =0;
                }
            }

        for(char ch : noDup)
            {
                if(ch >= 'a' && ch <='z')
                {
                    strength += 1;
                }
                if(ch >= 'A' && ch <='Z')
                {
                    strength += 2;
                }
                if(ch >= '0' && ch <= '9')
                {
                    strength += 3;
                }
                if(ch == '!' || ch == '@' || ch == '#' || ch == '$')
                {
                    strength +=5;
                }
            }
        return strength ;
    }
};
