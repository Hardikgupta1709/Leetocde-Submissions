class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>& component,int node)
    {
        component.push_back(node);

        if(node == graph.size()-1)
        {
            ans.push_back(component);
            component.pop_back();
            return;
        }

        for(auto i: graph[node])
        {
            dfs(graph,ans,component,i);
        }
    component.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int>component;

        dfs(graph,ans,component,0);

    return ans;
    }
};
