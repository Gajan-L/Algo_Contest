// Q2 Number of Ways to Buy Pens and Pencils
// let x be how many pens could be purchased given total;
// iterate from 0 to x, find how many pencils could be purchased given total - i * cost of pens;
// time: O(n); space: O(1).
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0, a = max(cost1, cost2), b = min(cost1, cost2);
        long long n = total/a;
        for(long long i = 0; i <= n; i++){
            long long left = total - i * a;
            res += left/b + 1;
        }
        return res;
    }
};
