class Solution {
public:
    int mirrorDistance(int n) {

        int og = n;
        int x =0;
        while(n>0)
        {
            int digit = n %10;
            x = x * 10 + digit;
            n /= 10;
        }

        return abs(og-x);
    }
};
