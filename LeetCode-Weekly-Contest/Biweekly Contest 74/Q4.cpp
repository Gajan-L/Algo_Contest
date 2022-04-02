// Q4: Minimum White Tiles After Covering With Carpets
// dp[i][j] min white tiles if we use ith carpets(end) to cover j tile;
// do nothing: dp[i][j] = dp[i][j - 1] + s[i] - '0';
// cover it: dp[i][j] = d[i - 1][max(j - carpertLen, 0)];
// for i == 0, cover it == INT_MAX since we have no carpet to cover;
class Solution {
    int dp[1001][1001];
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        dp[0][0] = 0;
        for(int i = 0; i <= numCarpets; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j - 1] + floor[j - 1] - '0', (i > 0 ? dp[i - 1][max(j - carpetLen, 0)]:INT_MAX));
            }
        }
        return dp[numCarpets][n];
    }
};
