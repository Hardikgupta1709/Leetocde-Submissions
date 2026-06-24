class Solution {
public:
    void makeParent(vector<int>&parent, vector<int>&rank)
    {
        for(int i=0; i<parent.size(); i++)
        {
            parent[i] =i;
            rank[i] =0;
        }
    }

    int findParent(vector<int>&parent, int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int i, int j, vector<int>& parent, vector<int>&rank)
    {
        int u = findParent(parent,i);
        int v = findParent(parent,j);

        if(rank[u]< rank[v])
        {
            parent[u] =v;
        }
        else if(rank[v]< rank[u])
        {
            parent[v] =u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int>parent(isConnected.size());
        vector<int>rank(isConnected.size());

        makeParent(parent,rank);

        for(int i=0; i<isConnected.size(); i++)
        {
            for(int j=0; j<isConnected.size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    unionSet(i,j,parent,rank);
                }
            }            
        }

        int count =0;

        for(int i=0; i<isConnected.size(); i++)
        {
            if(findParent(parent,i) == i)
            {
                count++;
            }
        }
    return count;
    }
};
