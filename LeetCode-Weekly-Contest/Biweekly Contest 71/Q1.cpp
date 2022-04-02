// Q1: Minimum Sum of Four Digit Number After Splitting Digits

class Solution {
public:
    int minimumSum(int num) {
        priority_queue<int,vector<int>,greater<int>> pq;
        while(num){
            pq.push(num %1 0);
            num /= 10;
        }
        int a = 0, b = 0;
        while(!pq.empty()){
            a = a*10 + pq.top();
            pq.pop();
            b = b*10 + pq.top();
            pq.pop();
        }
        return a+b;
    }
};
