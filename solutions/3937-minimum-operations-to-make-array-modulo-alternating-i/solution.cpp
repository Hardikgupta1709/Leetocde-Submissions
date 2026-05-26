class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans =INT_MAX;

        int x=0;
        int y=0;

        while(x<k)
        {
            int y=0;
            while(y < k)
            {
                if(x != y)
                {
                    int ops =0;
                    for(int i=0; i<nums.size(); i++)
                    {
                        int rem = nums[i] %k;
                        if(i%2 ==0)
                        {
                            int c1 = (x-rem + k)%k;
                            int c2 = (rem-x + k)%k;

                            ops += min(c1,c2);
                        }
                        else 
                        {
                            int c1 = (y-rem + k)%k;
                            int c2 = (rem-y + k)%k;

                            ops += min(c1,c2);
                        }
                    }
                    ans = min(ans,ops);
                }
                y++;
            }
            x++;
        }
    return ans;
    }
};
