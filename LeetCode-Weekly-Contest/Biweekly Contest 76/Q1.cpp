// Q1 Find Closest Number to Zero
// keep tracking the closest number to zero
// time: O(n); space: O(1);
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closestDist = INT_MAX;
        int closestNum = INT_MIN;
        for(int num: nums){
            if(abs(num) < closestDist){
                closestDist = abs(num);
                closestNum = num;
            }
            else if(abs(num) == closestDist && num > closestNum){
                closestNum = num;
            }
        }
        return closestNum;
    }
};
