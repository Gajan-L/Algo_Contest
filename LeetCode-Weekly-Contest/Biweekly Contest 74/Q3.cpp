// Q3: Minimum Operations to Halve Array Sum
// each time pop out max -> priorty_queue<double, vector<double>, less<double>>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0, target;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += (double) nums[i];
            pq.push((double) nums[i]);
        }
        target = sum/2;
        int cnt = 0;
        while(sum > target){
            double m = pq.top(); pq.pop();
            sum -= m/2;
            pq.push(m/2);
            cnt++;
        }
        return cnt;
    }
};
