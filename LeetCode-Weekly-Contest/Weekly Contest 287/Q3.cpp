// Q3： Maximum Candies Allocated to K Children
// binary search the first len that cannot be distribute to children
// return len - 1;
// Time: O(mlog(n)), m is the size of candies, n is the maximum len of candy; Space: O(1);

class Solution {
    bool canDivide(vector<int>& candies, int l, long long k){
        if(l == 0)
            return true;
        long long sum = 0;
        for(int i = 0; i < candies.size(); i++){
            sum += candies[i] / l;
        }
        return sum >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = 1e7 + 1;
        while(l < r){
            int m = (r + l) >> 1;
            if(canDivide(candies, m, k))
                l = m + 1;
            else
                r = m;
        }
        return l - 1;
    }
};
