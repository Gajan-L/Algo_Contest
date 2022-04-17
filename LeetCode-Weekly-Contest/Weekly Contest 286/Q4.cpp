// Q4: Maximum Value of K Coins From Piles
// For some certain piles[i], we will take 0 ~ piles[i].size() from it.
// dp(i,j) = max(dp(i + 1, j - k) + sum(piles[0] to piles[k]))
// I did it both top-down and bottom-up. But top-down somehow got me TLE.
// Time: O(n*k^2); Space: O(n*k);

// top-down
class Solution {
public:
    int helper(int i, int k ,vector<vector<int>>& piles, vector<vector<int>>& dp){
        if(dp[i][k] != 0){
            return dp[i][k];
        }
        if(k == 0 || i == piles.size())
            return dp[i][k] = 0;
        int res = helper(i + 1, k, piles, dp);
        int cur = 0;
        for(int j = 0; j < min((int)piles[i].size(),k); j++){
            cur += piles[i][j];
            res = max(res, cur + helper(i + 1, k - j - 1, piles, dp));
        }
        return res;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        return helper(0, k, piles, dp);
    }
};

// bottom-up
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size(), res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i + 1][j];
                int cur = 0;
                for(int m = 0; m < min((int)piles[i].size(), j); m++){
                    cur += piles[i][m];
                    dp[i][j] = max(dp[i][j], cur + dp[i + 1][j - m - 1]);
                }
                if(j == k)
                    res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
