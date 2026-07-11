class Solution {
public:
    void makeParent(vector<int>&parent, vector<int>& rank, int n)
    {
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] =0;
        }
    }

    int findParent(int node, vector<int>& parent)
    {
        if(parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node], parent);
    }

    void doUnion(int i, int j, vector<int>& parent, vector<int>&rank)
    {
        int u = findParent(i,parent);
        int v = findParent(j,parent);

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
            parent[v] = u;
            rank[u]++;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int connected =0;

        vector<int>parent(n);
        vector<int>rank(n);

        makeParent(parent,rank,n);

        for(int i=0; i<edges.size(); i++)
        {
            int u = findParent(edges[i][0], parent);
            int v = findParent(edges[i][1], parent);

            if(u != v)
            {
                doUnion(u,v,parent,rank);
            }
        }

        vector<int> nodeCount(n,0);
        vector<int> edgeCount(n,0);
        for(int i=0; i<n; i++)
        {
            int root = findParent(i,parent);
            nodeCount[root]++;
        }

        for(int i=0; i<edges.size(); i++)
        {
            int root = findParent(edges[i][0], parent);
            edgeCount[root] ++;
        }

        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
            {
                int nodes = nodeCount[i];

                int reqEdges = nodes * (nodes-1)/2;

                if(edgeCount[i] == reqEdges)
                {
                    connected++;
                }
            }
        }
    return connected;
    }
};
