// Q1: Divide Array Into Equal Pairs
// if possible, all # of num should be even

class Solution {
    int a[501];
public:
    bool divideArray(vector<int>& nums) {
        memset(a,0,sizeof(a));
        for(int &num: nums)
            a[num]++;
        for(int &n : a){
            if(n % 2 != 0)
                return false;
        }
        return true;
    }
};
