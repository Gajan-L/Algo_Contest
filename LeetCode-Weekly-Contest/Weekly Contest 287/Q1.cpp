// Q1: Minimum Number of Operations to Convert Time
// calculate the absolution minutes and do subtraction

class Solution {
public:
    int convertTime(string current, string correct) {
        int s = ((int)(current[0] - '0') * 10 + (int) (current[1] - '0')) * 60 + (int)(current[3] - '0') * 10 + (current[4] - '0');
        int c = ((int)(correct[0] - '0') * 10 + (int) (correct[1] - '0')) * 60 + (int)(correct[3] - '0') * 10 + (correct[4] - '0');
        int diff = c - s, cnt = 0;
        while(diff != 0){
            if (diff >= 60)
                diff -= 60;
            else if (diff >= 15){
                diff -= 15;
            }
            else if (diff >= 5){
                diff -= 5;
            }
            else {
                diff--;
            }
            cnt++;
        }
        return cnt;
    }
};
