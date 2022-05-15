// Q2 Number of Ways to Split Array
// prefix sum and suffix sum

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> l(n), r(n);
        for (int i = 0; i < n; i++) {
            if(i == 0){
                l[i] = nums[i];
            }
            else{
                l[i] = l[i - 1] + nums[i];
            }
        }
        for (int i = n - 1; i >= 0; i--){
            if (i == n - 1){
                r[i] = 0;
            }
            else {
                r[i] = r[i + 1] + nums[i + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (l[i] >= r[i])
                ans++;
        }
        return ans;
    }
};
