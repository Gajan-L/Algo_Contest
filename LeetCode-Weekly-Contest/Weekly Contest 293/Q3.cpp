// Q3: Largest Combination With Bitwise AND Greater Than Zero
// consider every # in binary form
// if bitwise AND are greater than zero, there must be a least one bit that all of # have 1 in that bit
// we could just count the max frequence of 1 in all bits
// n = candidates.size(), candidates[i] <= m
// time: O(nlogm)
// space: O(1);

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(32, 0);
        for (int c : candidates) {
            int base = 0;
            while (c) {
                if (c & 1) {
                    freq[base]++;
                }
                base++;
                c /= 2;
            }
        }
        int ans = 0;
        for (int f : freq){
            //cout << f << endl;
            ans = max (ans, f);
        }
        return ans;
    }
};
