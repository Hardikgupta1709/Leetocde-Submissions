class Solution {
public:
    void makeParent(vector<int>& parent, vector<int> &rank ,int n)
    {
        for(int i=0; i<n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(int node, vector<int>&parent)
    {
        if(parent[node] == node)
        {
            return node;
        }

    return parent[node] = findParent(parent[node],parent);
    }

    void unionSet(int i, int j, vector<int>& parent, vector<int>& rank)
    {
        int u = findParent(i,parent);
        int v = findParent(j,parent);

        if(rank[u] < rank[v])
        {
            parent[u] =v;
        }
        else if(rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v] ++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<bool> ans;
        vector<int>parent(n);
        vector<int>rank(n);

        makeParent(parent,rank,n);

        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1] - nums[i] <= maxDiff)
            {
                unionSet(i,i+1,parent,rank);
            }
        }

        for(int i=0; i<queries.size(); i++)
        {
            int u = findParent(queries[i][0],parent);
            int v = findParent(queries[i][1],parent);

            if(u != v)
            {
                ans.push_back(false);
            }
             else
            {
                ans.push_back(true);
            }
        }
    return ans;
    }
};
