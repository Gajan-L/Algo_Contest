// Q2: Maximum Consecutive Floors Without Special Floors
// use a map to store the consecutive floors
// n = special.size()
// time: O(nlogn)
// space: O(n)

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        map<int, int> mp;
        mp[bottom] = top;
        for (auto sp : special) {
            auto it = mp.upper_bound(sp);
            it--;
            int from = it->first, to = it->second;
            mp.erase(it);
            mp[from] = sp - 1;
            mp[sp + 1] = to;
        }
        int ans = 0;
        for (auto [f ,t] : mp) {
            ans = max (ans, t - f + 1);
        }
        return ans;
    }
};
