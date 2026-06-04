class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        int total = 0;
        for(int i = num1; i<=num2; i++)
        {
            string s = to_string(i);
            int peak =0;
            int valley =0;

            if(s.size() < 3)
            {
                continue;
            }

            for(char j=1; j<s.size()-1; j++)
            {
                if(s[j]>s[j-1] && s[j]>s[j+1])
                {
                    peak ++;
                }
                else if(s[j]<s[j-1] && s[j]<s[j+1])
                {
                    valley ++;
                }
            }
            total += peak+valley;
        }
        return total;
    }
};
