class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums){
        long long cnt=0;
        int streak=0;

        for(auto x:nums){
            if(x==0){
                streak++;
                cnt+=streak;
            }
            else{
                streak=0;
            }
        }
        return cnt;
    }
};

// Time = O(n)
// Space = O(1)