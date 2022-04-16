// Q3 Design an ATM Machine
// simulate the procedures;
// time: O(1) for construction, deposit(), withdraw();
// space: O(1);

class ATM {
    vector<long long> depositList;
    vector<int> denominations = {20,50,100,200,500};
public:
    ATM() {
        depositList.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            depositList[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ret(5,0);
        for(int i = 4; i >= 0; i--){
            if(amount >= denominations[i]){
                int cnt = amount/denominations[i];
                if(depositList[i] >= cnt){
                    amount %= denominations[i];
                    ret[i] = cnt;
                }
                else{
                    amount -= denominations[i] * depositList[i];
                    ret[i] = depositList[i];
                }
            }
        }
        if(amount > 0){
            return {-1};
        }
        else{
            for(int i = 0; i < 5; i++){
                depositList[i] -= ret[i];
                
            }
        }
        return ret;
    }
};
