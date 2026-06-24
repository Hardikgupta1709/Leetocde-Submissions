class Solution {
public:
    void dfs(unordered_map<int,list<int>>& adjList, unordered_map<int,bool>& visited, vector<int>& disc, vector<int>& low, int parent, vector<vector<int>>& ans, int node, int& timer)
    {
        visited[node] = true;
        low[node] = disc[node] = timer++;

        for(auto nbr : adjList[node])
        {
            if(nbr == parent)
            {
                continue;
            }
            if(!visited[nbr])
            {
                dfs(adjList, visited, disc, low, node, ans, nbr, timer);
                low[node] = min(low[node], low[nbr]);

                // if bridge
                if(low[nbr] > disc[node])
                {
                    ans.push_back({node,nbr});
                }
            }
            else
            {
                // backEdge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,list<int>>adjList;
        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        int timer =0;
        int parent = -1;
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(adjList, visited, disc, low, parent, ans, i, timer);
            }
        }
    return ans;
    }
};
