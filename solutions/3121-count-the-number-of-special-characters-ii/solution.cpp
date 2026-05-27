class Solution {
public:
    int numberOfSpecialChars(string word) {

        int count =0;

        for(char i='a'; i<='z'; i++)
        {
            int lower =-1;
            int upper =-1;

            for(int j=0; j<word.size(); j++)
            {
                if(word[j] == i - 32)
                {
                    upper = j;
                    break;
                }
            }
            for(int j=0; j<word.size(); j++)
            {
                if(word[j] == i)
                {
                    lower = j;
                }
            }

            if(upper == -1 || lower == -1)
            {
                continue;
            }

            if(upper > lower)
            {
                count ++;
            }

        }
        return count;
    }
};
