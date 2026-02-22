class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<int> arr;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] != ' ') {
                count++;  
            } 
            else {
                if (count > 0) {
                    arr.push_back(count);
                    count = 0;   
                }
            }
        }
        if (count > 0) {
            arr.push_back(count);
        }

        return arr.back();
    }
};
