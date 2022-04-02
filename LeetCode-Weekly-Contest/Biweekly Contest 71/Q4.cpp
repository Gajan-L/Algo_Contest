// Minimum Difference in Sums After Removal of Elements
// two way dp;
// dp[i]: min sum of n elements: fron 0 to m + i
// from right to left cal max n elements
// res = min( minsum(0 to i), maxsum(j, n - 1))

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n / 3;
        priority_queue<int, vector<int>, less<int>> pql;
        priority_queue<int, vector<int>, greater<int>> pqr;
        vector<long long> dp(m + 1);
        int i = 0;
        dp[0] = 0;
        while(i < 2 * m){
            while(pql.size() < m){
                pql.push(nums[i]);
                dp[0] += nums[i];
                i++;
            }
            pql.push(nums[i]);
            dp[i - m + 1] = dp[i - m] + nums[i] - pql.top();
            pql.pop();
            i++;
        }
        long long res = dp[m], j = n - 1, sum = 0;
        while(j >= m - 1){
            while(pqr.size() < m){
                pqr.push(nums[j]);
                sum += nums[j];
                j--;
            }
            res = min(res, dp[j - m + 1] - sum);
            pqr.push(nums[j]);
            sum += nums[j] - pqr.top();
            pqr.pop();
            j--;
        }
        
        return res;
    }
};
