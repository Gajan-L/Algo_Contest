// Q1: Cells in a Range on an Excel Sheet
// read and print
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        char sCol = s[0], eCol = s[3];
        int sRow = s[1] - '0', eRow = s[4] - '0';
        for(int i = sCol - 'a'; i <= eCol - 'a'; i++){
            for(int j = sRow; j <= eRow; j++){
                string s;
                s += 'a' + i;
                s += to_string(j);
                res.push_back(s);
            }
        }
        return res;
    }
};
