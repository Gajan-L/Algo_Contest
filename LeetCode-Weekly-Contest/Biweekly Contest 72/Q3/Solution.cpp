// think one step ahead
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 != 0)
            return res;
        long long i = 1;
        while (finalSum) {
            if (finalSum >= 2 * (2 * i + 1)) {
                finalSum -= 2 * i;
                res.push_back(2 * i);
            }
            else {
                res.push_back(finalSum);
                break;
            }
            i++;
        }
        return res;
    }
};
