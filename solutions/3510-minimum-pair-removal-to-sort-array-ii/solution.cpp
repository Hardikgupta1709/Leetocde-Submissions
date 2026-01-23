#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<long long> val(n);
        for (int i = 0; i < n; ++i) val[i] = nums[i];


        vector<int> nxt(n, -1), prv(n, -1);
        for (int i = 0; i < n; ++i) {
            if (i > 0) prv[i] = i - 1;
            if (i < n - 1) nxt[i] = i + 1;
        }

        // Priority queue to find the leftmost minimum-sum pair: {sum, left_index}
        set<pair<long long, int>> pairs;
        int decreasing_count = 0;

        for (int i = 0; i < n - 1; ++i) {
            pairs.insert({val[i] + val[i+1], i});
            if (val[i] > val[i + 1]) decreasing_count++;
        }

        int ops = 0;
        while (decreasing_count > 0) {
            ops++;

            auto it = pairs.begin();
            long long current_sum = it->first;
            int i = it->second;
            pairs.erase(it);

            int j = nxt[i]; 
            int p = prv[i]; 
            int nn = nxt[j]; 


            if (p != -1) {
                pairs.erase({val[p] + val[i], p});
                if (val[p] > val[i]) decreasing_count--;
            }
            if (nn != -1) {
                pairs.erase({val[j] + val[nn], j});
                if (val[j] > val[nn]) decreasing_count--;
            }
            if (val[i] > val[j]) decreasing_count--;


            val[i] = current_sum;
            nxt[i] = nn;
            if (nn != -1) prv[nn] = i;


            if (p != -1) {
                pairs.insert({val[p] + val[i], p});
                if (val[p] > val[i]) decreasing_count++;
            }
            if (nn != -1) {
                pairs.insert({val[i] + val[nn], i});
                if (val[i] > val[nn]) decreasing_count++;
            }
        }

        return ops;
    }
};
