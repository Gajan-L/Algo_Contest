class Solution {
public:
    int minSteps(string s, string t) {
        int a[26],b[26];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int res = 0;
        for(char c: s){
            a[c - 'a']++;
        }
        for(char c: t){
            b[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            res += abs(a[i] - b[i]);
        }
        return res;
    }
};
