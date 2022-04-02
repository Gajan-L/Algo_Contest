// Q2: Append K Integers With Minimal Sum
// tricky thing: I thought n in nums are unique, turns out not!!!

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res = 0;
        long long i = 1;
        unordered_set<int> mp;
        priority_queue<int, vector<int>,greater<int>> pq;
        for(int n : nums){
            mp.insert(n);
        }
        for(int s: mp){
            pq.push(s);
        }
        while(k){
            if(!pq.empty()){
                while(!pq.empty()){
                    if(i == pq.top()){
                        i++;
                        pq.pop();
                    }
                    else
                        break;
                }
                if(pq.empty()){
                    res += (i + (k + i - 1)) * k/2;
                    k = 0;
                }
                else{
                    if(pq.top() - i >= k){
                        res += (i+(i+k-1))*k/2;
                        k = 0;
                    }
                    else{
                        res += (i + pq.top() - 1)*(pq.top() - i)/2;
                        k -= pq.top() - i;
                        i = pq.top()+1;
                        pq.pop();
                    }
                }
            }
            else{
                res += (i + (k+i-1)) * k/2;
                k = 0;
            }
        }
        return res;
    }
};
