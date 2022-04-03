// Find Players With Zero or One Losses
// use two hashtables to map player with total matches and score
// if matches == score ==> no lost;
// if matches == score + 1 ==> only one lost;
// could use a array to store then we do not need to sort

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        unordered_map<int, int> sp;
        for (auto m : matches) {
            int winner = m[0];
            int loser = m[1];
            mp[winner]++;
            mp[loser]++;
            sp[winner]++;
        }
        vector<vector<int>> res(2);
        for (auto a: mp) {
            int p = a.first;
            int m = a.second;
            int s = sp[p];
            if (m == s)
                res[0].push_back(p);
            if (m == s + 1)
                res[1].push_back(p);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};
