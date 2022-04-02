// Q3: Design Bitset
// tricky one: use a bool type isFlip indicate if the bitset is flip or not.

class Bitset {
    vector<bool> bs;
    bool isFlip;
    int cnt;
    int s;
public:
    Bitset(int size) {
        bs = vector<bool>(size, false);
        isFlip = false;
        cnt = 0;
        s = size;
    }
    
    void fix(int idx) {
        if(isFlip){
            if(bs[idx]){
                bs[idx] = false;
                cnt++;
            }
        }
        else{
            if(!bs[idx]){
                bs[idx] = true;
                cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if(isFlip){
            if(!bs[idx]){
                bs[idx] = true;
                cnt--;
            }
        }
        else{
            if(bs[idx]){
                bs[idx] = false;
                cnt--;
            }
        }
    }
    
    void flip() {
        isFlip = !isFlip;
        cnt = s - cnt;
    }
    
    bool all() {
        return cnt == s;
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        for(bool b: bs){
            if((!isFlip && b) || (isFlip && !b))
                s += "1";
            else
                s += "0";
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
