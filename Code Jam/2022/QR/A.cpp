// punched cards
// each cell contail same element except for the top left;

#include<vector>
#include<iostream>
using namespace std;

int n, r, c;
vector<vector<char>> match = { {'+', '-'}, {'|', '.'} };

void solve() {
	for (int i = 0; i < 2 * r + 1; i++) {
		for (int j = 0; j < 2 * c + 1; j++) {
			if (i < 2 && j < 2)
				cout << ".";
			else
				cout << match[i % 2][j % 2];
		}
		cout << '\n';
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		cout << "Case #" << i << ":\n";
		solve();
	}
}
