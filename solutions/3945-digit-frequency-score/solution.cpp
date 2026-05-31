class Solution {
public:
    int digitFrequencyScore(int n) {
        string num = to_string(n);

        unordered_map<int,int> freq;

        for(char ch : num)
            {
                freq[ch - '0']++;
            }

        int score =0 ;

        for(auto it: freq)
            {
                score += it.first * it.second;
            }

    return score;
    }
};
