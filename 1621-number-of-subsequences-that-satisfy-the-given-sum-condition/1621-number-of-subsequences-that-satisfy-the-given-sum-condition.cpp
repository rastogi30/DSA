class Solution {
public:
    int MOD=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        // since number so sequence not matter isliye sort kr diya
        sort(nums.begin(), nums.end());
        int l=0;
        int r=n-1;
        int result=0;

        // precompute the power of 2...to call in O(1)
        vector<int>power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%MOD;
        }

        while(l<=r){
            // if max+min less to beech wale lo ya mt lo koi farak nhi
            // isliye permutation lena h ya nhi so 2^r-l
            if(nums[l]+nums[r]<=target){
                int diff=r-l;
                result= (result+ power[diff])%MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return result;
    }
};

// TC: O(n log n)
// Space: O(n)