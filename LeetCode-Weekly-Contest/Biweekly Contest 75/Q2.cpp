// Q2: Find Triangular Sum of an Array
// use a queue to simulate the procedure
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> res;
        for (int num: nums)
            res.push(num);
        while(res.size() != 1){
            int n = res.size();
            for (int i = 0; i < n - 1; i++){
                int n1 = res.front(); res.pop();
                int next = n1 + res.front();
                res.push(next % 10);
            }
            res.pop();
        }
        return res.front();
    }
};
