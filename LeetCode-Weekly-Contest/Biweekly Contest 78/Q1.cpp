// Q1: Find the K-Beauty of a Number
// store all digits and use a slide window
// time: O(logn)
// space: O(logn)
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        vector<int> a;
        int b = num;
        while (b){
            a.push_back(b % 10);
            b /= 10;
        }
        if (a.size() < k)
            return 0;
        long long cur = 0, ans = 0, base = 1;
        for (int i = 0, j = 0; j < a.size(); ) {
            while (j < a.size() && j - i < k) {
                cur += a[j++] * base;
                base *= 10;
            }
            if (cur != 0 && num % cur == 0)
                ans++;
            cur /= 10;
            base /= 10;
            i++;
        }
        return ans;
    }
};
