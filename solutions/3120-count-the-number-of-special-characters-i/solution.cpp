class Solution {
public:
    int numberOfSpecialChars(string word) {
        int spec =0;

        sort(word.begin(), word.end());

        word.erase(unique(word.begin(),word.end()), word.end());

        for(char i =0; i<word.size(); i++)
        {
            for(char j=i; j<word.size(); j++)
            {
                if(abs(word[i] - word[j]) == 32)
                {
                    spec++;
                }
            }
        }
    return spec;
    }
};
