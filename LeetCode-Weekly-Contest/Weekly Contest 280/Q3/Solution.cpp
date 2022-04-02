/*  beans = [1,4,5,6]
*   final state(num of the beans in one non-empty bag): 0, 1, 4, 5, 6
*   start from 0 (we take all beans out): 1+4+5+6 = takes
*   from 0 to 1: 0+3+4+6 = pre_take - (1-0)*4
*   from 1 to 4: 1+0+1+2 = pre_take - (4-1)*3
*   ...
*/
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long current = 0;
        long long total = 0;
        for (auto b : beans) {
            total += b;
        }
        long long best = total;
        int N = beans.size();
        for (int i = 0; i < N; i++) {
            long long delta = beans[i] - current;
            total -= delta * (N - i);
            best = min(best, total);
            total += beans[i];
            current = beans[i];
        }
        return best;
    }
};
