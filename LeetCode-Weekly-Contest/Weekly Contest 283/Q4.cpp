// Q4: Replace Non-Coprime Numbers in Array
// it's more like a math problem, lcm = a * b/gcd(a,b)

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int n: nums){
            res.push_back(n);
            while(res.size()>1 &&  __gcd(res[res.size()-1], res[res.size()-2]) > 1){
                long long a = res[res.size()-1], b = res[res.size()-2], g = __gcd(a,b);
                res.pop_back();
                res.pop_back();
                res.push_back(a*b/g);
            }
        }
        return res;
    }
};
