// Chain Reactions
// for each intersecting node, we take the minimum from its pointer, and cut the edge of other pointer (sum them up to the final res). 
// update the node value with the maximum of its value with the minimum pointer value

#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<ctime>
#include<cstdlib>

using namespace std;

int n, m, ans;
#define INT_MAX 2147483647


int solve(vector<int>& f, vector<int>& p, vector<vector<int>>& adj) {
	int res = 0;
	for (int i = m; i > 0; i--) {
		if (adj[i].size() > 1) {
			int mini = INT_MAX;
			int sum = 0;
			for (int j = 0; j < adj[i].size(); j++) {
				sum += f[adj[i][j]];
				mini = min(mini,f[adj[i][j]]);
			}
			res += sum - mini;
			f[i] = max(mini, f[i]);
		}
		int next = p[i];
		if (next == 0)
			res += f[i];
		else if (adj[next].size() == 1)
			f[next] = max(f[next], f[i]);
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		vector<int> f(m + 1);
		vector<int> p(m + 1);
		vector<vector<int>> adj(m + 1);
		for (int i = 1; i <= m; i++)
			cin >> f[i];
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
			adj[p[i]].push_back(i);
		}
		cout << "Case #" << i << ": ";
		cout << solve(f, p, adj) << "\n";
	}
}
