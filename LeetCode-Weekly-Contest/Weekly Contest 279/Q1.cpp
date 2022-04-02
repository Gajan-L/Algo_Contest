// Q1: Sort Even and Odd Indices Independently
// use two priority_queue for odd and even
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return nums;
        priority_queue<int, vector<int>, less<int>> odd;
        priority_queue<int, vector<int>, greater<int>> even;
        for(int i = 0; i < n; i++){
            if(i % 2)
                odd.push(nums[i]);
            else
                even.push(nums[i]);
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(i % 2){
                res.push_back(odd.top());
                odd.pop();
            }
            else{
                res.push_back(even.top());
                even.pop();
            }
        }
        return res;
        
    }
};
