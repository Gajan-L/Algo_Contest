class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto i : map) {
            vector<int> tmp = i.second;
            for(int i = 0; i < tmp.size(); i++)
                for (int j = i + 1; j < tmp.size(); j++) {
                    if (tmp[i] * tmp[j] % k == 0)
                        count++;
                }
        }
        return count;
    }
};
