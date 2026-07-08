class Solution {
public:
    void bfs(vector<vector<int>>& adjList, int& minLength, int node, int n)
    {
        vector<int> parent(n, -1);
        vector<int> dist(n, -1);

        queue<int> q;

        dist[node] = 0;
        q.push(node);

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(auto i : adjList[top])
            {
                if(dist[i] == -1)
                {
                    parent[i] = top;
                    dist[i] = dist[top] + 1;
                    q.push(i);
                }
                else if(i != parent[top])
                {
                    int cycleLength = dist[top] + dist[i] + 1;
                    minLength = min(minLength, cycleLength);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int minLength = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            bfs(adjList, minLength, i, n);
        }

        if(minLength == INT_MAX)
        {
            return -1;
        }
    return minLength;
    }
};
