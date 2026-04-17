class Solution {
public:
    int reverseNum(int x)
    {
        int rev =0;
        while(x > 0)
        {
            int digit = x%10;
            rev  = rev * 10 + digit;
            x /= 10;
        }
    return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {

        int mini = INT_MAX;
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++)
        {
            int rev= reverseNum(nums[i]);

            if(mp.count(nums[i]))
            {
                int dist = abs(mp[nums[i]] - i);
                mini = min(mini, dist);
            }

            mp[rev]  = i;
        }

        if(mini == INT_MAX)
        {
            return -1;
        }
        return mini;
    }
};
