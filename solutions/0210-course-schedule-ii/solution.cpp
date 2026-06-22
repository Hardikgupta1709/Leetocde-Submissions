class Solution {
public:
    void orderOfCourse(unordered_map<int,list<int>>& adjList, unordered_map<int,bool>&visited, stack<int>&s, int node)
    {
        visited[node] = true;

        for(auto i: adjList[node])
        {
            if(!visited[i])
            {
                orderOfCourse(adjList,visited,s,i);
            }
        }
        s.push(node);
    }

    bool isCyclic(unordered_map<int,list<int>>& adjList, unordered_map<int,bool>&visited, unordered_map<int,bool>& dfs_visited, int node)
    {
        visited[node] = true;
        dfs_visited[node] = true;

        for(auto i: adjList[node])
        {
            if(!visited[i])
            {
                if(isCyclic(adjList,visited,dfs_visited,i))
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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;

        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfs_visited;
        stack<int>s;

        vector<int>ans;

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                bool cycleExists = isCyclic(adjList,visited,dfs_visited,i);
                if(cycleExists)
                {
                    return ans;
                }
            }
        }

        visited.clear();

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                orderOfCourse(adjList,visited,s,i);
            }
        }

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            ans.push_back(top);
        }

        
    return ans;
    }
};
