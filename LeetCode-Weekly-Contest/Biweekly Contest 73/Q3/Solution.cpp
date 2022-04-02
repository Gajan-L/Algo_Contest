// dfs approach
// update the ancestors list of all descendants using dfs
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> res(n);
        for(vector<int> e : edges){
            graph[e[0]].push_back(e[1]);
        }
        for(int i = 0; i < n; i++){
            vector<bool> vis(n);
            dfs(graph, i, i, vis, res);
        }
        return res;
    }
    void dfs(vector<vector<int>>& g, int src, int i, vector<bool>& vis, vector<vector<int>>& res){
        if(i != src)
            res[i].push_back(src);
        vis[i] = true;
        for(int v: g[i]){
            if(!vis[v]){
                dfs(g, src, v, vis, res);
            }
        }
    }
};
