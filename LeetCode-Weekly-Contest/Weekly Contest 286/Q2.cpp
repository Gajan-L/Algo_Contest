// Q2: Minimum Deletions to Make Array Beautiful
// iterate from 0 tp n, if nums[i] != nums[i + 1], go to next pair(i += 2)
// otherwise, delete all from[i, k) that is equal to nums[i], make nums[i] and nums[k] a pair, i = k + 1;
// if iterate to the end and still have one element, delete it;
// Time: O(n), Space: O(1);

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), i = 0, res = 0;
        if(n == 1)
            return 1;
        while(i < n){
            if(i + 1 < n && nums[i] != nums[i + 1]){
                i += 2;
            }
            else{
                if(i == n - 1){
                    res++;
                    break;
                }
                else{
                    int k = 1;
                    while(i + k < n && nums[i + k] == nums[i]) k++;
                    if(i + k == n){
                        res += k;
                        break;
                    }
                    else{
                        res += k - 1;
                        i += k + 1;
                    }
                }
            }
        }
        return res;
    }
};
