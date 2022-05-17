// Q4: Count Integers in Intervals
// use a set of Interval to store separate Intervals
// each time when add a interval
// 1) find the equal_range of the interval and update that new interval
// 2) update the count of integers in the set
// n = size of data streams (operations)
// time: add = O(logn) (average); count = O(1);
// space: O(n);

struct Interval { 
    int start, end;
    friend bool operator< (Interval a, Interval b) {
        return a.end < b.start;
    }
};

class CountIntervals {
    set<Interval> s;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto [b, e] = s.equal_range({left, right});
        int c = right - left + 1;
        if (b != e) {
            for (auto it = b; it != e; it++) {
                int ls = max (left, it->start), le = min (right, it->end);
                c -= le - ls + 1;
            }
            left = min (left, b->start);
            right = max (right, prev(e)->end);
            s.erase(b, e);
        }
        s.insert({left, right});
        cnt += c;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
