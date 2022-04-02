/*  Note that the constraints is in a small scale, we could use the bitmask to represent the situation of each slot
*   In this case, I use a 3-bit bitmask for a slot which indicate how many elements in this slot
*   Then we need a cache for storing in case that the memory would be out of limit.
*   The space we need would be 3^numSlots for considering all situation, that is emtpy, has 1 element, has 2 elements
*   Base case would be index out of range, then we return 0. if already calculate, just return the result.
*   Otherwise, we check for insert current element into any possible slot( <2 )
*   dp(i,mask) = max(dp(i,mask), (nums[ind] & slot) + dp(ind+1, mask+bit))
*/
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> cache(pow(3, numSlots), 0);
        return dp(0, 0, nums, numSlots, cache);
    }
    int dp(int ind, int mask, vector<int>& nums, int numSlots, vector<int>& cache) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (cache[mask] > 0) {
            return cache[mask];
        }
        for (int slot = 1, bit = 1; slot <= numSlots; slot++, bit*=3) {
            if ( mask / bit % 3 < 2) {
                cache[mask] = max(cache[mask], (nums[ind] & slot) + dp(ind + 1, mask + bit, nums, numSlots, cache));
            }
        }
        return cache[mask];
    }
};
