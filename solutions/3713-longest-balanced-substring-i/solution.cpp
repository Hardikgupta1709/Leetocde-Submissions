class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int subLength = 0;

        for(int i = 0; i < n; i++) {

            int freq[26] = {0};   

            for(int j = i; j < n; j++) {

                freq[s[j] - 'a']++;   

                int first = 0;
                bool valid = true;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        if(first == 0)
                            first = freq[k];
                        else if(freq[k] != first) {
                            valid = false;
                            break;
                        }
                    }
                }

                if(valid)
                    subLength = max(subLength, j - i + 1);
            }
        }

        return subLength;
    }
};

