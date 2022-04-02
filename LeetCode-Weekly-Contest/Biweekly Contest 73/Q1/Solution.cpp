class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        unordered_map<int, int> candidate;
        for(int i = 0; i < n; i++){
            if(candidate.count(nums[i]) && nums[i - 1] != key)
                candidate[nums[i]]++;
            if(nums[i] == key && i < n - 1){
                if(!candidate.count(nums[i + 1]))
                    candidate[nums[i + 1]] = 1;
                else
                    candidate[nums[i + 1]]++;
            }              
        }
        int res;
        int cnt = 0;
        for(auto s: candidate){
            if(s.second > cnt){
                cnt = s.second;
                res = s.first;
            }
        }
        return res;
    }
};
