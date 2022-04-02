// Q4: Minimum Weighted Subgraph With the Required Paths
// assume there is node i between src1 and src2 with dest, the path would be src1 - i - dest, src2 - i - dest;
// then we do 3 times Dijkstra from src1, src2(using original graph) and dest(using reverse graph)
// find the min(distSrc1[i] + distSrc2[i] + distDest[i])
// Note that this covers the case that we take two separate path form scr1 to dest and src2 to dest when i = dest;
// Also covers the overlapping problem as the total weight of overlapping node will always be larger than the first overlapping node.
// Time: O((E+V)logV + V); Space: O(E+V)(graph and dist).
// if using an adjacency matrix to represent the graph, 
// it may take up to O(V^2) time and space, which may cause TLE or MLE (- -) since in most cases there may not be that much edges

class Solution {
    const long long inf = 1e18;
private:
	vector<long long> Dijkstra(vector<vector<pair<int, long long>>>& adj, int src) {
		int n = adj.size();
		vector<long long> dist(n, inf);
		dist[src] = 0;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.push(make_pair(0, src));
		while (!pq.empty()) {
			auto [d, cur] = pq.top();
            pq.pop();
			if (d != dist[cur]) 
                continue;
			for (auto [next, w] : adj[cur]) {
				if (dist[next] > d + w) {
					dist[next] = d + w;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		return dist;
	}
public:
	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		// build the graph and the graph with reverse edges
		vector<vector<pair<int, long long>>> adj(n);
		vector<vector<pair<int, long long>>> reverseAdj(n);
		int u, v, w;
		for (auto& e : edges) {
			u = e[0], v = e[1], w = e[2];
			adj[u].push_back(make_pair(v, w));
			reverseAdj[v].push_back(make_pair(u, w));
		}
        
        // 3 Dijkstra
		vector<long long> distSrc1 = Dijkstra(adj, src1);
		vector<long long> distSrc2 = Dijkstra(adj, src2);
		vector<long long> distDest = Dijkstra(reverseAdj, dest);
		// find the smallest w[i]
		long long ans = inf;
		for (int i = 0; i < n; i++) {
            ans = min(ans, distSrc1[i] + distSrc2[i] + distDest[i]);
		}
		return ans == inf ? -1 : ans;
	}
};
