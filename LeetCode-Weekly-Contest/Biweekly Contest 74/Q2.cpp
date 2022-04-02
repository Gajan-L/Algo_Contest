// Q2: Maximize Number of Subsequences in a String
// greedy way: either insert p[0] into first or p[1] into last
// if(p[0] == p[1]) C(2, count)
// else count how many p[1] appear after each p[0];

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        string text1 = pattern[0] + text;
        string text2 = text + pattern[1];
        vector<int> l,r;
        long long cnt1 = 0, n = text1.length();
        for(int i = n - 1; i > -1; i--){
            if(text1[i] == pattern[1])
                cnt1++;
            if(text1[i] == pattern[0])
                l.push_back(cnt1);
        }
        long long cnt2 = 0;
        for(int i = n - 1; i > -1; i--){
            if(text2[i] == pattern[1])
                cnt2++;
            if(text2[i] == pattern[0])
                r.push_back(cnt2);
        }
        long long res1 = 0, res2 = 0;
        if(pattern[0] == pattern[1]){
            res1 = cnt1*(cnt1-1)/2;
            res2 = cnt2*(cnt2-1)/2;
        }
        else{
            for(int &num: l)
                res1 += num;
            for(int &num: r)
                res2 += num;
        }
        return max(res1, res2);        
    }
};
