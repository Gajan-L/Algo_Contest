// Q4: Minimum Time to Remove All Cars Containing Illegal Goods
// dp problem;
// dp[i](from left to right) min cost time if remove i cars.
// s[i] is legal, then dp[i] = dp[i-1];
// if not, dp[i] = min( dp[i-1] + 2, i);
// then we do it again from right to left;
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            dp[i] = (s[i - 1] == '0') ? dp[i - 1] : min(dp[i - 1] + 2, i);
        int res = dp[n], suf = 0;
        for(int i = n; i > 0; --i){
            if(s[i - 1] == '1'){
                suf = min(suf + 2, n - i + 1);
                res = min(res, suf + dp[i - 1]);
            }
        }
        return res;
    }
};
