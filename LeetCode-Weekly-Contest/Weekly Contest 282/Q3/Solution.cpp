// binary search
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(),time.end());
        long long l = 0;
        long long r = (long long) time[n - 1] * (long long) totalTrips;
        while(l < r){
            long long m = l + ((r - l) >> 2);
            long long cnt = 0;
            for(int t : time){
                if(t <= m)
                    cnt += m/t;
                else 
                    break;
            }
            if(cnt >= totalTrips)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
