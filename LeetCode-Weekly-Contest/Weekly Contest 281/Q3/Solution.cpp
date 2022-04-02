/*  I used a priority_queue of pair(index, freq[i]): alphabetically larger char pop first
*   use cur to store the cur insering char to avoid repeating out of limits
*   if char is not just inserted, insert it either reach to limit or max of freq;
*   if char is just inserted, turn to second one and insert only one to avoid violating the repeat limits constriant
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0)
                pq.push(make_pair(i, freq[i]));
        }
        int cur = -1;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (p.first == cur) {
                if (!pq.empty()) {
                    pair<int, int> p2 = pq.top();
                    pq.pop();
                    pq.push(p);
                    res += 'a' + p2.first;
                    cur = p2.first;
                    p2.second--;
                    if (p2.second != 0) {
                        pq.push(p2);
                    }
                }
                else
                    break;
            }
            else {
                if (p.second <= repeatLimit) {
                    cur = p.first;
                    for (int i = 0; i < p.second; i++) {
                        res += 'a' + p.first;
                    }
                }
                else {
                    cur = p.first; 
                    for (int i = 0; i < repeatLimit; i++) {
                        res += 'a' + p.first;
                    }
                    p.second -= repeatLimit;
                    pq.push(p);
                }
            }
        }
        return res;
    }
};
