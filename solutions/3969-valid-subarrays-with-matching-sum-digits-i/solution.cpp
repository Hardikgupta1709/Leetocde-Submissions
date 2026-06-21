class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        int count =0;

        for(int i=0; i<nums.size(); i++)
        {
            long long sum =0;
            for(int j=i; j<nums.size(); j++)
            {
                sum += nums[j];

                int lastDigit = sum%10;

                if(lastDigit != x)
                {
                     continue;   
                }

                long long temp = sum;

                while(temp>=10)
                {
                    temp /=10;
                }

                int firstDigit = temp;

                if(firstDigit == x)
                {
                    count ++;
                }
            }
        }
    return count;
    }
};
