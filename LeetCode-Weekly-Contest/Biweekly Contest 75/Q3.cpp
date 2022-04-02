// Q3: Number of Ways to Select Buildings
// since there are only '0' and '1' in the s;
// we could group the same continuous '0' and '1' int to one group
// for any middle m of group(not front and end), if we take this group as the middle element of the final
// assume group m is '1', we could calculate how many ways by (how many '0' before m) * (num of group m) * (how many '0' after m)
// we sum up all the possible m then we could get the answer
// Time: O(n)n ,n: length of s; Space: O(n);
class Solution {
public:
    long long numberOfWays(string s) {
        int i = 0, j = 0, n = s.length();
        long long cnt = 0;
        vector<long long> group;
        while(j < n){
            while(j < n && s[j] == s[i]) j++;
            group.push_back(j - i);
            i = j;
        }
        int m = group.size();
        if(m >= 3){
            vector<long long> l(m);
            vector<long long> r(m);
            for(int i = 0; i < m; i++){
                l[i] = (i < 2) ? group[i] : (l[i - 2] + group[i]);
            }
            for(int i = m - 1; i >= 0; i--){
                r[i] = (i > m - 3) ? group[i] : (group[i] + r[i + 2]);
            }
            for(int i = 1; i <= m - 2; i++){
                cnt += group[i] * l[i - 1] * r[i + 1];
            }
        }
        return cnt;
    }
};
