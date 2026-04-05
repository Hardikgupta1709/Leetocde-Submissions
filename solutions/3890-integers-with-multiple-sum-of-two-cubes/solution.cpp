class Solution {
public:
    void solve(int n, vector<int>& ans)
    {
        unordered_map<int,int> mp;
        for(int i=1; i*i*i <= n; i++)
            {
                for(int j=i+1; j*j*j <= n; j++)
                    {
                        int tempGood = i*i*i + j*j*j;

                        if(tempGood > n)
                        {
                            break;
                        }

                        mp[tempGood] ++;
                    }
            }
        for(auto it: mp)
            {
                if(it.second >= 2)
                    {
                        ans.push_back(it.first);
                    }
            }
    }
    
    vector<int> findGoodIntegers(int n) {
        vector<int> ans;

        int good =n;
        solve(n,ans);
        sort(ans.begin(), ans.end());

    return ans;
    }
};
