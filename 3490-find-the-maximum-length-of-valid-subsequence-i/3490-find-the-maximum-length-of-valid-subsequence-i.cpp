class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }

        int alternative=1;
        int parity=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            int currparity=nums[i]%2;
            if(currparity!=parity){
                alternative++;
                parity=currparity;
            }
        }

        return max(even, max(odd,alternative));
    }
};

// tc:O(n)