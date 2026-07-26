class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        map<int, pair<int,int>> table;

        unordered_set<int> present1;
        unordered_set<int> present2;

        for(int i=0; i<series1.size(); i++)
            {
                int u = series1[i][0];
                int wt1 = series1[i][1];

                table[u].first = wt1;
                present1.insert(u);
            }

        for(int i=0; i<series2.size(); i++)
            {
                int v = series2[i][0];
                int wt2 = series2[i][1];

                table[v].second = wt2;
                present2.insert(v);
            }

        int nextValue1 = 0;
        int nextValue2 = 0;

        vector<int>timestamps;

        for(auto it: table)
            {
                timestamps.push_back(it.first);
            }

        for(int i=timestamps.size()-1; i>=0; i--)
            {
                int timestamp = timestamps[i];

                if(present1.find(timestamp) != present1.end())
                {
                    nextValue1 = table[timestamp].first;
                }
                else
                {
                    table[timestamp].first = nextValue1;
                }


                if(present2.find(timestamp) != present2.end())
                {
                    nextValue2 = table[timestamp].second;
                }
                else
                {
                    table[timestamp].second = nextValue2;
                }
            }

        vector<vector<int>> ans;

        for(auto it: table)
            {
                int timestamp = it.first;
                int sum = it.second.first + it.second.second;

                ans.push_back({timestamp,sum});
            }
        return ans;
    }
};
