// Q3: Maximum White Tiles Covered by a Carpet
// use two map to 1) map left and right; 2) map[l] with the # of times before (like a prefix sum)
// time: O(nlogn)
// space: O(n)
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        map<int, int> s;
        map<int, int> mp;
        sort(tiles.begin(), tiles.end());
        for (auto& t: tiles) {
            int l = t[0], r = t[1];
            s[l] = r;
            mp[l] = r - l + 1;
            auto it = mp.find(l);
            if(it != mp.begin()){
                it--;
                mp[l] += it->second;
            }
        }
        int ans = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            auto [l, r] = *it;
            int bound = l + carpetLen - 1;
            auto next = s.upper_bound(bound);
            int total;
            next--;
            total = mp[next->first];
            
            if (bound < s[next->first]){
                total -= s[next->first] - bound;
            }
            if(it != s.begin()){
                total -= mp[prev(it)->first];
            }
            
            ans = max (ans, total);
        }
        return ans;
    }
};
