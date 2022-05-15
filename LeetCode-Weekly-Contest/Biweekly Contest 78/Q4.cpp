// Q4: Substring With Largest Variance
// first apporach: use the freq to store freq of all letter for s[0: i] and use that to get all substring's freq.
// time: O(n^2)
// space: O(n)
class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        vector<vector<int>> freq;
        vector<int> base(26,0);
        freq.push_back(base);
        for (int i = 0; i < n; i++){
            auto cur = freq.back();
            cur[s[i] - 'a']++;
            freq.push_back(cur);
        }
        
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            vector<int> a = freq[i];
            for (int j = i + 1; j <= n; j++) {
                vector<int> b = freq[j];
                vector<int> cur(26);
                int maxi = 0, mini = INT_MAX;
                for (int k = 0; k < 26; k++){
                    cur[k] = b[k] - a[k];
                    if (cur[k] != 0){ 
                        maxi = max (maxi, cur[k]);
                        mini = min (mini, cur[k]);
                    }
                }
                ans = max (ans, maxi - mini);
            }
        }
        return ans;
    }
};

// second apporach
// like a kanade's algorithm, each time use two letter for checking
// time: O(n)
// space: O(1)
class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int ans = 0;
        
        for (char p = 'a'; p <= 'z'; p++) {
            for (char q = 'a'; q <= 'z'; q++) {
                if (p == q) continue;
                
                int cntP = 0;
                int cntQ = 0;
                
                bool reverse = false;
                
                for (auto c : s){
                    if (c == p) cntP++;
                    if (c == q) cntQ++;
                    
                    if (cntQ > 0)
                        ans = max (ans, cntP - cntQ);
                    else if (cntQ == 0 && reverse)
                        ans = max (ans, cntP - cntQ - 1);
                    if (cntQ > cntP) {
                        cntQ = cntP = 0;
                        reverse = true;
                    }
                }
            }
        }
        
        return ans;
    }
};
