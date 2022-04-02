// Q4: Sum of Scores of Built Strings
// the famous z-function, very similar like manacher

class Solution {
public:
    vector<int> z_function(const string& s) {
        int n = s.size();
        vector<int> z(n, n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r && z[i - l] < r - i + 1) 
                z[i] = z[i - l];
            else 
                for (z[i] = max(0, r - i + 1); i + z[i] < n && s[z[i]] == s[i + z[i]]; z[i] += 1);
            if (i + z[i] - 1 > r) 
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    long long sumScores(string s) {
        auto z = z_function(s);
        long long res = 0;
        for (int x : z) res += x;
        return res;
    }
};
