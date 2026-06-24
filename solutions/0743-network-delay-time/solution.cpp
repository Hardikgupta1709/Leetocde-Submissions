class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(int i=0; i<times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adjList[u].push_back(make_pair(v,w));
        }

        vector<int>dist(n+1,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push(make_pair(0,k));

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int Nodeweight = top.first;
            int node = top.second;

            for(auto it: adjList[node])
            {
                int nghbr = it.first;
                int edgeWeight = it.second;

                if(Nodeweight + edgeWeight < dist[nghbr])
                {
                    dist[nghbr] = Nodeweight + edgeWeight;
                    pq.push(make_pair(dist[nghbr],nghbr));
                }
            }
        }

        int ans =0;
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            ans = max(ans,dist[i]);
        }
    return ans;
    }
};
