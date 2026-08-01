class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long>diff(n+1,0);
        for(const auto& boost : boosts)
            {
                int l = boost[0];
                int r = boost[1];
                long long v = boost[2];

                diff[l] += v;
                diff[r+1] -= v;
            }

        vector<long long>b(n,0);
        long long current_bonus = 0;

        for(int i=0; i<n; i++)
            {
                current_bonus += diff[i];
                b[i] = current_bonus;
            }

        long long r =0;

        for(int i= n-1; i>=0;i --)
            {
                if(r>0)
                {
                    r = r+ monsters[i];
                }
                else
                {
                    r = max(0LL, (long long)monsters[i] - b[i]);
                }
            }
        return r;
    }
};
