// Q2: Partition Array According to Given Pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0;
        vector<int> res;
        vector<int> bigger;
        for(int n: nums){
            if(n < pivot)
                res.push_back(n);
            else if(n == pivot)
                cnt++;
            else
                bigger.push_back(n);
        }
        while(cnt--){
            res.push_back(pivot);
        }
        for(int n: bigger)
            res.push_back(n);
        return res;
    }
};
