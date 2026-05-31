class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> freq(n+1, 0);

        for(int x: nums)
            {
                if(x<=n)
                {
                    freq[x]++;
                }
            }

        vector<int> ans;

        int i=0;

        while(i<n)
            {
                int mex=0;

                while(mex<=n && freq[mex]>0)
                    {
                        mex++;
                    }

                if(mex == 0)
                {
                    ans.push_back(0);

                    if(nums[i]<=n)
                    {
                        freq[nums[i]]--;
                    }
                    i++;
                }
                else
                {
                    ans.push_back(mex);

                    vector<int> seen(mex,0);

                    int need = mex;

                    while(i<n && need>0)
                        {
                            int x = nums[i];

                            if(x< mex && !seen[x])
                            {
                                seen[x] =1;
                                need--;
                            }
                            if(x<=n)
                            {
                                freq[x]--;
                            }
                            i++;
                        }
                }
            }
        return ans;
    }
};
