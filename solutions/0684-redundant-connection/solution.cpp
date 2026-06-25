class Solution {
public:
    void makeParent(vector<int>&parent, vector<int>&rank)
    {
        for(int i=0; i<parent.size(); i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int>& parent, int node)
    {
        if(parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int i, int j, vector<int>&parent, vector<int>&rank)
    {
        int u = findParent(parent, i);
        int v = findParent(parent, j);

        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if(rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        vector<int> rank(edges.size()+1);
        makeParent(parent, rank);

        for(int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            int pa = findParent(parent,a);
            int pb = findParent(parent,b);

            if(pa == pb)
            {
                return edges[i];
            }
            else
            {
                unionSet(a,b,parent,rank);
            }
        }
    return {};
    }
};
