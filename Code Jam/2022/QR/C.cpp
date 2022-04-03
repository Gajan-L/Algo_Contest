// d1000000
// we could use a priority queue that each time comparing if there is possible way to extend the path

#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int n, m;
int sum = 1000000;
#define INT_MAX 2147483647

void solve(vector<int>& s) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int num : s)
		pq.push(num);
	int cur = 1;
	while (pq.size()) {
		if (cur <= pq.top()) {
			cur++;
		}
		pq.pop();
	}
	cout << --cur << "\n";
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		vector<int> s(m);
		for (int i = 0; i < m; i++)
			cin >> s[i];
		cout << "Case #" << i << ": ";
		solve(s);
	}
}
