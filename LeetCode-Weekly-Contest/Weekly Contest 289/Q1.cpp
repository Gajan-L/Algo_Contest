// Q1 Calculate Digit Sum of a String
// basic simulation
// time: O(n), space: O(1);

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string newS = "";
            for(int i = 0, j = 0; j < s.length();){
                while(j < s.length() && j - i < k) j++;
                string substr = s.substr(i, j - i);
                int sum = 0;
                for(int i = 0; i < substr.length(); i++){
                    sum += substr[i] - '0';
                }
                newS += to_string(sum);
                i = j;
            }
            s = newS;
        }
        return s;
    }
};
