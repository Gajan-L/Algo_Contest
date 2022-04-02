class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(string w: words){
            if(w.length() >= pref.length()){
                bool flag = true;
                for(int i = 0; i < pref.length(); i++){
                    if(w[i] != pref[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    cnt++;
            }
        }
        return cnt;
    }
};
