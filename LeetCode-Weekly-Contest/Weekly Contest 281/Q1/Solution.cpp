class Solution {
public:
    int countEven(int num) {
        int res = 0;
        int i = num/10;
        int j = num%10;
        if(i == 0){
            res = num/2;
        }
        else if(1<=i&&i<10){
            res+=4+(i-1)*5+j/2;
            if(i%2==0||(i%2==1&&j%2==1))
                res+=1;
        }
        else if(10<=i&&i<100){
            res+=4+45+(i-10)*5+j/2;
            int t =i%10;
            i/=10;
            if((i%2==t%2)||((i%2!=t%2)&&j%2==1))
                res+=1;
        }
        else{
            res += 4+5*9+5*10*9;
        }
        return res;
    }
};
