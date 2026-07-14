class Solution {
public:
    bool dfs(unordered_map<int,list<int>>& adjList, vector<bool>& visited, int target, int node)
    {
        if(node == target)
        {
            return true;
        }

        visited[node] = true;

        for(auto it : adjList[node])
        {
            if(!visited[it])
            {
                if(dfs(adjList, visited, target, it))
                {
                    return true;
                }
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        unordered_map<int,list<int>> adjList;
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        for(int i=0; i<queries.size(); i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];

            vector<bool> visited(numCourses, false);

            if(dfs(adjList,visited,y,x))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        
    return ans;
    }
};
