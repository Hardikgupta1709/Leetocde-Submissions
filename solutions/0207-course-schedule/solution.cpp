class Solution {
public:
    bool check(unordered_map<int,list<int>>&adjList, unordered_map<int,bool>&visited,unordered_map<int,bool>& dfs_visited, int node)
    {
        visited[node] = true;
        dfs_visited[node] = true;

        for(auto i: adjList[node])
        {
            if(!visited[i])
            {
                if(check(adjList,visited,dfs_visited,i))
                {
                    return true;
                }
            }
            else if(dfs_visited[i])
            {
                return true;
            }
        }
        dfs_visited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;

        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfs_visited;

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                bool ans = check(adjList,visited,dfs_visited,i);
                if(ans == 1)
                {
                    return false;
                }
            }
        }
    return true;
    }
};
