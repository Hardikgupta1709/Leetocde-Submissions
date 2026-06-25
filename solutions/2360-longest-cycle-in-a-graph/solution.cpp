class Solution {
public:
    void dfs(vector<int>& edges, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfs_visited, vector<int>& length, int node, int& ans, int currLength)
    {
        visited[node] = true;
        dfs_visited[node] = true;
        length[node] = currLength;

        int nbr = edges[node];

        if(nbr != -1)
        {
            if(!visited[nbr])
            {
                dfs(edges,visited,dfs_visited, length, nbr, ans, currLength+1);
            }   
            else if(dfs_visited[nbr])
            {
                int cycleLength = length[node] - length[nbr] +1;
                ans = max(ans,cycleLength);
            }
        }
        dfs_visited[node] = false;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfs_visited;
        vector<int>length(n,0);

        int ans = -1;

        for(int i=0; i<edges.size(); i++)
        {
            if(!visited[i])
            {
                dfs(edges, visited, dfs_visited, length, i, ans, 0);
            }
        }

        return ans;
    }
};
