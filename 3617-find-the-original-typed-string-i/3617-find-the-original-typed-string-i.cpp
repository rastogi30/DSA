class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        for(int i=1;i<word.size();i++){
            if(word[i-1]==word[i]){
                ans++;
            }
        }
        return ans;
    }
};
// TC: O(n)
// space : O(1);

// class Solution {
// public:
//     int possibleStringCount(string word) {
//         unordered_map<char,int>mp;
//         for(auto ch:word){
//             mp[ch]++;
//         }

//         int ans=1;
//         for(auto i:mp){
//             if(i.second>1 ){
//                 ans+=i.second-1;
//             }
//         }
//         return ans;
//     }
// };

// TC:O(n)
// space O(k)  26 se jyada nhii