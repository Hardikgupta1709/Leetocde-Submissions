class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int count =0;

        for(int i=0; i<n; i++)
            {
                int count0 =0;
                int count1 =0;
                for(int j=0; j<=i; j++)
                    {
                        if(s[j] == '0')
                        {
                            count0 ++;
                        }
                        else
                        {
                            count1++;
                        }
                    }
                if(abs(count0 - count1) <=1)
                {
                    count++;
                }
            }
        return count;
    }
};
