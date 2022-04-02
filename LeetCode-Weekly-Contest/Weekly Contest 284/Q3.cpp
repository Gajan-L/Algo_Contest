// Q3: Maximize the Topmost Element After K Moves
// if k = 0, just return nums[0];
// if n == 1, since every time we need to make a move
// then if k % 2 == 0, the final movement would be placing the only element back, else the final movement would be taking the only element out;
// if k = 1, we have only one move that is taking the first element out;
// if k > n, we could take all elements out, and insert the max of them in the k step;
// else for k - 1 steps, we take all elements out, and for the k step, we either put the max of removal of take another one out.
// Time: O(n); Space: O(1).

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)
            return nums[0];
        if(n == 1)
            return (k % 2 == 0) ?nums[0]: -1;
        if(k == 1)
            return nums[1];
        int maxi = INT_MIN;
        int i = 0;
        while(i < n && k > 1){
            maxi = max(maxi, nums[i++]);
            k--;
        }
        if(i == n || i == n - 1)
            return maxi;
        return max(maxi, nums[i + 1]);
    }
};
