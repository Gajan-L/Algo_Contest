/* make all elements of odd index and even index change to the most common element in two set */
class Solution {
    int getMax(unordered_map<int, int> map) {
        int maxCount = 0;
        int max;
        for (auto i : map) {
            if (i.second > maxCount) {
                maxCount = i.second;
                max = i.first;
            }
        }
        return max;
    }
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> odd;    // num[i] and count
        unordered_map<int, int> even;   // num[i] and count
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (even.count(nums[i])) {
                    even[nums[i]]++;
                }
                else
                    even[nums[i]] = 1;
            }
            else {
                if (odd.count(nums[i])) {
                    odd[nums[i]]++;
                }
                else
                    odd[nums[i]] = 1;
            }
        }
        int evenMax = getMax(even);
        int oddMax = getMax(odd);
        if (evenMax == oddMax) {
            if (even[evenMax] >= odd[oddMax]+ nums.size()%2) {
                odd[oddMax] = 0;
                oddMax = getMax(odd);
            }
            else {
                even[evenMax] = 0;
                evenMax = getMax(even);
            }
        }
        int evenNum = nums.size() / 2 + nums.size() % 2;
        int oddNum = nums.size() - evenNum;
        return (evenNum - even[evenMax]) + (oddNum - odd[oddMax]);
    }
};
