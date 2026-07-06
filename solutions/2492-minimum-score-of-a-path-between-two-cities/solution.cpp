class Solution {
public:
    void dfs(unordered_map<int,list<pair<int,int>>>&adjList, unordered_map<int,bool>&visited, int&mini, int node)
    {
        visited[node] = true;

        for(auto it: adjList[node])
        {
            mini = min(mini,it.second);
            if(!visited[it.first])
            {
                dfs(adjList,visited,mini,it.first);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int>>> adjList;
        int mini = INT_MAX;

        for(int i=0; i<roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adjList[u].push_back(make_pair(v,wt));
            adjList[v].push_back(make_pair(u,wt));

        }
        unordered_map<int,bool> visited;

        dfs(adjList,visited,mini,1);
    return mini;
    }
};
