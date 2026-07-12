class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        long long total =0;

        for(int i=0; i<nums.size(); i++)
            {
                total += nums[i];
            }


        long long ops = (total + k-1)/ k-1;

        if(ops <= 0)
        {
            return 0;
        }

        long long ans =0;

        if(ops % 2 == 0)
        {
            ans = ((ops/2)%1000000007)* ((ops+1)%1000000007) % 1000000007;
        }
        else
        {
            ans = (ops % 1000000007)* (((ops+1)/2)% 1000000007)% 1000000007;
        }
    return ans;
    }
};
