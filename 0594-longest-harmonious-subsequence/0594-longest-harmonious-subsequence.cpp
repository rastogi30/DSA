class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int  ans=0;

        int left=0;

        for(int right=0;right<n;right++){
            // shrink the window upto diff become <=1
            while(nums[right]-nums[left]>1){
                left++;
            }

            // ==1 update the answer with the new length
            if(nums[right]-nums[left]==1){
                ans=max(ans, right-left+1);
            }
        }
        return ans;  //TC: O(nlogn) due to sorting and in search it is O(n).
    }
};

//Using map and counting
//T.C : O(n)
//S.C : O(n)
// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         unordered_map<int, int> mp;

//         int result = 0; //to store maximum subsequence length

//         for(int &num : nums) {
//             mp[num]++;
//         }

//         for(int &num : nums) {
//             int minNum = num;
//             int maxNum = num+1;

//             if(mp.count(maxNum)) {
//                 result = max(result, mp[minNum] + mp[maxNum]);
//             }
//         }

//         return result;
//     }
// };

// class Solution {
// public:
//     // tc O(n*n)
//     int findLHS(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         int  ans=0;

//         int i=0;
//         int j=n-1;
//         while(i<n && i<=j){
//             if(nums[j]-nums[i]==1){
//                 ans=max(ans, (j-i+1));
//                 i++;
//                 j=n-1;
//             }
//             else{
//                 j--;
//             }
//         }
//         return ans;
//     }
// };