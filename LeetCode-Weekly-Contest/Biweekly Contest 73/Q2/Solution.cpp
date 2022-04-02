class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> p;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int cur = nums[i];
            int m = 0;
            int real = 0;
            // remember to consider 0;
            if(cur == 0)
                real = mapping[cur];
            else{
                int base = 1;
                while(cur){
                    real += mapping[cur%10]*base;
                    cur/=10;
                    base*=10;
                }
            }
            p.push_back({real,i});
        }
        sort(p.begin(),p.end());
        vector<int> res;
        for(pair pa: p){
            res.push_back(nums[pa.second]);
        }
        return res;
    }
};
