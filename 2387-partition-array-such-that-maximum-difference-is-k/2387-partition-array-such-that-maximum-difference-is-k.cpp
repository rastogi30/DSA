class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        // we require max min so sort to make it easy...
        sort(nums.begin(), nums.end());

        int cnt=1;
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            // if difference increase then sart the new subsequence...
            if(nums[i]-mini>k){
                cnt++;
                mini=nums[i];
            }
        }
        return cnt;
    }
};

// TC O(nlogn + O(n))= O(nlogn);