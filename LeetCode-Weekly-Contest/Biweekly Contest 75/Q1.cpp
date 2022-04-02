// Q1: Minimum Bit Flips to Convert Number
// take an xor and calculate the count of '1'.
// Time: O(log(max(start, goal)); Space: O(1).
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start ^ goal, cnt = 0;
        printf("%d\n",t);
        while(t){
            if(t & 1)
                cnt++;
            t = t >> 1;
        }
        return cnt;
    }
};
