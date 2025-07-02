class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance=0;
        int start=0;
        int kitnaKam=0;

        for(int i=0;i<gas.size();i++){
            // balance find kata jane ka kya aa  raha
            balance+=gas[i]-cost[i];

            // negative to kam me add kara..final mei check kr ne ke liye or start incresse kr diya
            // fir se start to balance 0
            if(balance<0){
                kitnaKam+=balance;
                start=i+1;
                balance=0;
            }
        }

        // kitnaKam use kiya jis se ek baar ke loop mei kam ho jaye..
        // so balance add kr ke 0 ya positive means round complete
        if(balance+kitnaKam >=0){
            return start;
        }
        else{
            return -1;
        }
    }
};

// Tc: O(n);
// space : O(1);