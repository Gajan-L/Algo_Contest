// Q4: Maximum Score of a Node Sequence
// for every edge[x,y], we want to find maximum adj of x and y and that they are unique.
// in worse case we would check for 3 nodes
// time: O(ElogE + 9*E)
// space: O(E); 
struct cmp{
    bool operator()(const pair<int, int> a, const pair<int, int> b){
        return a.first > b.first;
    }
};

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back({scores[e[1]], e[1]});
            adj[e[1]].push_back({scores[e[0]], e[0]});
        }
        for(int i = 0; i < n ; i++){
            sort(adj[i].begin(), adj[i].end(), cmp());
        }
        int res = -1;
        for(auto e : edges){
            int x = e[0], y = e[1];
            for(int i = 0; i < 3 && i < adj[x].size(); i++){
                for(int j = 0; j < 3 && j < adj[y].size(); j++){
                    if(adj[x][i].second != y && adj[y][j].second != x && adj[x][i].second != adj[y][j].second){
                        res = max(res, scores[x] + scores[y] + adj[x][i].first + adj[y][j].first);
                    }
                }
            }
        }
        return res;
    }
};
