class Solution {
public:
    void bfs(int node, unordered_map<int,list<int>>& adjList, unordered_map<int,bool>& suspicious)
    {
        queue<int> q;
        q.push(node);

        suspicious[node] = true;

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(auto nbr : adjList[top])
            {
                if(!suspicious[nbr])
                {
                    suspicious[nbr] = true;
                    q.push(nbr);
                }
            }
        }   
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;

        unordered_map<int,list<int>>adjList;
        for(int i=0; i<invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adjList[u].push_back(v);
        }

        unordered_map<int,bool> suspicious;

        bfs(k, adjList, suspicious);


        for(int i=0; i<invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if(!suspicious[u] && suspicious[v])
            {
                for(int j=0; j<n; j++)
                {
                    ans.push_back(j);
                }
                return ans;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(!suspicious[i])
            {
                ans.push_back(i);
            }
        }

    return ans;
    }
};
