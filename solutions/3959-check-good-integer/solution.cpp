class Solution {
public:
    bool checkGoodInteger(int n) {
        string s = to_string(n);

        long long sum = 0;
        long long squaresum =0;
   
        for(int i=0; i<s.size(); i++)
            {
                int digit = s[i] - '0';

                sum += digit;
                squaresum += digit * digit;
            }


        if(squaresum - sum >=50)
        {
            return true;
        }
    return false;
    }
};
