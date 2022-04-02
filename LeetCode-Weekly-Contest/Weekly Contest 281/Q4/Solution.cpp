/*  for pair(i,j), select j from left to right, and consider all possible i from left to j
*   get gcd(j,k), then k/gcd(j,k) must be one cd of i
*   each time we reach a new j, we get d[k/gcd(i,j)] and add it to res, then make nums[j] one candidate of i for latter j
*   update the count for all cd of i
*/

class Solution {
    void update(vector<long long>& d, int k){
        for(int i=1;i*i<=k;i++){
            if(k%i==0){
                if(i==k/i)
                    d[i]++;
                else{
                    d[i]++;
                    d[k/i]++;
                }
            }
        }
    }
public:
    long long coutPairs(vector<int>& nums, int k) {
        long long res = 0;
        int n =nums.size();
        vector<long long> d(1e5+5,0);
        for(int i = 0;i < n; i++){
            int r = k/(__gcd(nums[i],k));
            res+= d[r];
            update(d,nums[i]);
        }
        return res;
    }
};
