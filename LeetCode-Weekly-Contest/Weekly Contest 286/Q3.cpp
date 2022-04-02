// Q3: Find Palindrome With Fixed Length
// Since we are going to find the i-th palindrome, we just need to consider the half of the lenght
// I use a string to generate the second half
// Time: O(n); Space: O(1) no extra space except for the res;
class Solution {
public:
    long long stoll(string s){
        long long res = 0; 
        int n = s.length(), i = 0;
        while(i < n){
            res *= 10;
            res += (s[i++] - '0');
        }
        return res;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int half = ((intLength + 1) >> 1), maxP = 9 * pow(10, half - 1);
        vector<long long> res;
        for(int q: queries){
            if(q <= maxP){
                int s = q + pow(10, half - 1) - 1;
                string cur = to_string(s);
                if(intLength & 1){
                    int i = cur.length() - 2;
                    while(i >= 0)
                        cur.push_back(cur[i--]);
                }
                else{
                    int i = cur.length() - 1;
                    while(i >= 0)
                        cur.push_back(cur[i--]);
                }
                res.push_back(stoll(cur));
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};
