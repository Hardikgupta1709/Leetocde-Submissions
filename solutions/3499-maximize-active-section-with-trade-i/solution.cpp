class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string augmented = '1' + s + '1';
        int countOne = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                countOne++;
            }
        }

        int maxi = countOne;

        for(int i = 1; i < augmented.size() - 1; i++)
        {
            if(augmented[i] == '1' && augmented[i - 1] == '0')
            {
                int j = i;
                while(j < augmented.size() - 1 &&
                      augmented[j] == '1')
                {
                    j++;
                }
                if(j < augmented.size() - 1 &&
                   augmented[j] == '0')
                {
                    int leftZero = 0;
                    int rightZero = 0;

                    int k = i - 1;

                    while(k >= 1 && augmented[k] == '0')
                    {
                        leftZero++;
                        k--;
                    }

                    k = j;

                    while(k < augmented.size() - 1 &&
                          augmented[k] == '0')
                    {
                        rightZero++;
                        k++;
                    }

                    int totalOne =
                        countOne + leftZero + rightZero;

                    maxi = max(maxi, totalOne);
                }

                i = j - 1;
            }
        }
        return maxi;
    }
};
