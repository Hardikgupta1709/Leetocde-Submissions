class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > 9*n)
        {
            return -1;
        }
        
        if(s == 0)
        {
            return 0;
        }

        string digit = "";
        int counter =0;

        while(counter < n)
            {
                int maxi = -1;

                for(int i=0; i<=9; i++)
                    {
                        int remainingSum = s-i;
                        int remainingDigit = n-counter-1;

                        if(remainingSum >=0 && remainingSum <= remainingDigit*9)
                        {
                            maxi = max(maxi,i);
                        }
                    }
                digit += to_string(maxi);

                s -= maxi;
                counter ++;
            }
        int ans = stoll(digit);
    return ans;
    }
};
