class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalKamai=0;
        int totalKharcha=0;

        for(int i=0;i<gas.size();i++){
            totalKamai+=gas[i];
            totalKharcha+=cost[i];
        }

        // agar kharcha jyada to return -1 not possible
        if(totalKharcha > totalKamai){
            return -1;
        }

        int index=0;
        int total=0;

        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];

            if(total<0){
                index=i+1;
                total=0;
            }
        }
        return index;
    }
};

// Tc: O(n);
// space: O(1);