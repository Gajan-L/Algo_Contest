// Q3: Minimum Cost to Set Cooking Time
// This is really irritating!!
// Several boundary case to consider:
//    1: t < 60: one case;
//    2: 60 <= t < 100: two cases;
//    3: 100 <= t < 6000: two cases;
//    4: t >= 6000: one case.

class Solution {
    int costOfTwoDigitOne(int t, int startAt, int moveCost, int pushCost){
        int res;
        int a = t / 10;
        int b = t % 10;
        if(a == 0){
            if(b == startAt)
                res = pushCost;
            else
                res = moveCost + pushCost;
        }
        else{
            if(a == startAt){
                if(b == a)
                    res = pushCost*2;
                else
                    res = pushCost*2 + moveCost;
            }
            else{
                if(b == a){
                    res = pushCost*2 + moveCost;
                }
                else
                    res = pushCost*2 + moveCost*2;
            }
        }
        return res;
    }
    int costOfTwoDigitTwo(int t, int startAt, int moveCost, int pushCost){
        int res;
        int a = t / 10;
        int b = t % 10;
        if(a == startAt){
            if(b == a)
                res = pushCost*2;
            else
                res = pushCost*2 + moveCost;
        }
        else{
            if(b == a){
                res = pushCost*2 + moveCost;
            }
            else
                res = pushCost*2 + moveCost*2;
        }
        return res;
    }
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int res;
        if(targetSeconds < 60){
            res = costOfTwoDigitOne(targetSeconds, startAt, moveCost, pushCost);
        }
        else if(targetSeconds < 100){
            int t1 = costOfTwoDigitOne(targetSeconds, startAt, moveCost, pushCost);
            int t2 = costOfTwoDigitOne(1 ,startAt, moveCost, pushCost) + costOfTwoDigitTwo(targetSeconds - 60, 1, moveCost, pushCost);
            res = min(t1, t2);
        }
        else{
            int m = targetSeconds / 60;
            int s = targetSeconds = targetSeconds - m * 60;
            if(m <= 99){
                if(s < 40){
                int t1 = costOfTwoDigitOne(m, startAt, moveCost, pushCost) + costOfTwoDigitTwo(s, m%10,moveCost,pushCost);
                int t2 = costOfTwoDigitOne(m - 1, startAt, moveCost, pushCost) + costOfTwoDigitTwo(s+60, (m-1)%10,moveCost,pushCost);
                res = min(t1,t2);
                }
                else{
                    res = costOfTwoDigitOne(m, startAt, moveCost, pushCost) + costOfTwoDigitTwo(s, m%10,moveCost,pushCost);
                }
            }
            else{
                res = costOfTwoDigitOne(m - 1, startAt, moveCost, pushCost) + costOfTwoDigitTwo(s+60, (m-1)%10,moveCost,pushCost);
            }
        }
        return res;
    }
};
