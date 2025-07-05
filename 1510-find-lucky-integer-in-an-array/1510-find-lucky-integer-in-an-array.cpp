class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(auto num:arr){
            mp[num]++;
        }

        for(auto i:mp){
            if(i.first==i.second){
                ans=max(ans,i.first);
            }
        }
        return ans;
    }
};
// TC : O(n)
// space : O(n)



// for small constraints it is valid
// TC : O(n)
// space : O(1)

// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         int freq[501] = {}; // array bana diya uthne size ka
//         for(int num : arr){
//             freq[num]++;
//         }
//         int ans = -1;
//         for(int i = 1; i <= 500; i++){
//             if(freq[i] == i){
//                 ans = i; since array so small to large isliye direct store 
//             }
//         }
//         return ans;
//     }
// };