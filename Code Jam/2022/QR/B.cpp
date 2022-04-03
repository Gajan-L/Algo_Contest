// 3D Printing
// take minimun of each color, if these is a sum without take zero from any color that up to 1000000, return
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int n;
int m[3][4];
int sum = 1000000;
#define INT_MAX 2147483647

void solve() {
	vector<int> mini(4, INT_MAX);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			mini[j] = min(mini[j], m[i][j]);
	}
	vector<int> res;
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (mini[i] == 0) break;
		if (result + mini[i] <= sum - 3 + i) {
			res.push_back(mini[i]);
			result += mini[i];
		}
		else {
			res.push_back(sum - 3 + i - result);
			result = sum - 3 + i;
		}
	}
	if (result == sum)
		cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << "\n";
	else
		cout << "IMPOSSIBLE\n";

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m[j][0] >> m[j][1] >> m[j][2] >> m[j][3];
		}
		cout << "Case #" << i << ": ";
		solve();
	}
}
