class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        unordered_map<int,pair<int,vector<int>>> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]].first++;
            mp[nums[i]].second.push_back(i);
        }
        int mini = INT_MAX;

        for(auto &it: mp)
        {
            if(it.second.first >= 3)
            {
                vector<int>& idx = it.second.second;

                for(int i=2; i<idx.size(); i++)
                {
                    int a =  idx[i];
                    int b = idx[i-1];
                    int c = idx[i-2];

                    int sum = abs(a-b) + abs(b-c) + abs(c-a);
                    mini = min(mini, sum);
                }
            }
        }

        if(mini == INT_MAX)
        {
            return -1;
        }
    return mini;
    }
};
