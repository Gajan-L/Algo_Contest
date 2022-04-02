// Q1: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
// for every key posi, push_back it pre k and next k index into res if it has not been pushed
// Time: O(n),  Space: O(1);

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                for(int j = res.empty() ? max((i - k), 0):max(res.back() + 1,(i - k)); j <= min(i + k, n - 1); j++){
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};
