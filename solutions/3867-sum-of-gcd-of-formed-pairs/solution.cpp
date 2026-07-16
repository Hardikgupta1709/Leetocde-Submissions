class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        if(nums.size() == 0)
        {
            return 0;
        }

        vector<int> mx(nums.size());
        mx[0] = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            mx[i] = max(nums[i],mx[i-1]);
        }

        vector<int> prefixGcd(nums.size());

        for(int i=0; i<nums.size(); i++)
        {
            prefixGcd[i] = gcd(nums[i],mx[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i=0;
        int j=prefixGcd.size()-1;

        long long sum =0;

        while(i<j)
        {
            int findGcd = gcd(prefixGcd[i],prefixGcd[j]);
            sum += findGcd;

            i++;
            j--;
        }
    return sum;
    }
};
