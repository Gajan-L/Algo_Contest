// Q2: Smallest Value of the Rearranged Number
// if n < 0 : get the max of -n by take digit from 9 to 0;
// if n == 0: return 0;
// if n > 0: if there is 0 in n, take one second min as the first, then take digit from 0 to 9.
class Solution {
    int a[10];
    long long getMax(long long n){
        while(n){
            a[n % 10]++;
            n /= 10;
        }
        long long res = 0;
        for(int i = 9; i >= 0; i--){
            while(a[i] != 0){
                res *= 10;
                res += i;
                a[i]--;
            }
        }
        return res;
    }
    long long getMin(long long n){
        while(n){
            a[n % 10]++;
            n /= 10;
        }
        long long res = 0;
        if(a[0] != 0){
            int second = 1;
            while(second < 10){
                if(a[second])
                    break;
                second++;
            }
            res = second;
            a[second]--;
        }
        while(a[0]){
            res *= 10;
            a[0]--;
        }
        for(int i = 1; i < 10; i++){
            while(a[i] != 0){
                res *= 10;
                res += i;
                a[i]--;
            }
        }
        return res;
    }
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        if(num < 0)
            return -1ll*getMax(-num);
        return getMin(num);
    }
};
