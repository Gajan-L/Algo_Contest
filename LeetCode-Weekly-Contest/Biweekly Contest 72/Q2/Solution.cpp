// for three num problem, focus on the middle one
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if (num % 3 == 0) {
            long long mid = num / 3;
            res.push_back(mid - 1);
            res.push_back(mid);
            res.push_back(mid + 1);
        }
        return res;
    }
};
