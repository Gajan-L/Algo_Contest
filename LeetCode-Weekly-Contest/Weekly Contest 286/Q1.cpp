// Q1: Find the Difference of Two Arrays
// use two set to store nums of two arrays
// Time: O(n); Space: O(n);

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        for(int i = 0; i < nums1.size(); i++)
            n1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            n2.insert(nums2[i]);
        vector<vector<int>> ans(2);
        for(auto a: n1){
            if(!n2.count(a))
                ans[0].push_back(a);
        }
        for(auto b: n2){
            if(!n1.count(b))
                ans[1].push_back(b);
        }
        return ans;
    }
};
