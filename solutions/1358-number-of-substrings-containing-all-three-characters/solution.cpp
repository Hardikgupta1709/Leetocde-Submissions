class Solution {
public:
    int numberOfSubstrings(string s) {
        int count =0;

        int freqA =0;
        int freqB =0;
        int freqC =0;

        int left =0;
        
        for(int i=0; i<s.size(); i++)
        {
                if(s[i] == 'a')
                {
                    freqA++;;
                }
                else if(s[i] == 'b')
                {
                    freqB++;;
                }
                else if(s[i] == 'c')
                {
                    freqC++;;
                }

                while(freqA > 0 && freqB > 0 && freqC > 0)
                {
                    count += s.size() - i;

                    if(s[left] == 'a')
                    {
                        freqA--;
                    }
                    else if(s[left] == 'b')
                    {
                        freqB--;
                    }
                    else if(s[left] == 'c')
                    {
                        freqC--;
                    }

                    left++;
                }
        }
    return count;
    }
};
