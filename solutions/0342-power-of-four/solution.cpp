class Solution {
public:
    bool isPowerOfFour(int n) {

        long base =4;

        for(int i=0; i<31; i++)
        {
            double val = pow(base,i);

            if(val > n)
            {
                break;
            }

            long long result  = (long long) (val + 0.5);
            if(result == n)
            {
                return true;
            }
        }
    return false;
    }
};
